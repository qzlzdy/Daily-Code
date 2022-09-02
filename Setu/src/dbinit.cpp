#include <filesystem>
#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;
namespace fs = filesystem;

int main(){
    sqlite3 *db;
    int res;
    auto statusCheck = [&](const string &desc, int code){
        if(res != SQLITE_OK && res != SQLITE_ROW && res != SQLITE_DONE){
            cerr << desc << " (" << res << "): "
                 << sqlite3_errmsg(db) << endl;
            exit(-1);
        }
    };
    res = sqlite3_open_v2("Setu.db", &db,
                          SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, nullptr);
    statusCheck("Database open failed", res);
    string CREATE_TABLE_SQL =
        "CREATE TABLE setus( "
        "illust_id INTEGER PRIMARY KEY, "
        "extension TEXT NOT NULL) ";
    char *errmsg;
    res = sqlite3_exec(db, CREATE_TABLE_SQL.c_str(), nullptr, nullptr, &errmsg);
    if(errmsg){
        cerr << "Create table failed: " << errmsg << endl;
        return -1;
    }
    string INSERT_SQL =
        "INSERT INTO setus(illust_id, extension) "
        "VALUES(?, ?)";
    fs::path root = fs::current_path();
    for(auto &file: fs::directory_iterator(root)){
        fs::path filename = file.path().filename();
        string stem = filename.stem().string();
        if(stem.front() != 'H'){
            continue;
        }
        int illust_id = stoi(stem.substr(1));
        string ext = filename.extension().string();
        sqlite3_stmt *stmt;
        res = sqlite3_prepare_v2(db, INSERT_SQL.c_str(), INSERT_SQL.length(),
                                &stmt, nullptr);
        statusCheck("Prepare failed", res);
        res = sqlite3_bind_int(stmt, 1, illust_id);
        statusCheck("Bind illust_id failed", res);
        res = sqlite3_bind_text(stmt, 2, ext.c_str(), ext.length(), SQLITE_STATIC);
        statusCheck("Bind extension failed", res);
        res = sqlite3_step(stmt);
        statusCheck("Insert failed", res);
        sqlite3_finalize(stmt);
    }
    sqlite3_close_v2(db);
    return 0;
}
