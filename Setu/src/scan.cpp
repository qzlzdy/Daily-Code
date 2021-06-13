#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

#include "sqlite3.h"

using namespace std;
namespace fs = filesystem;

int main(){
    fs::path root = "/run/media/qzlzdy/Data/qzlzdy/setu";
    sqlite3 *db;
    int rc;
    auto check_ok = [&rc, &db](const string &desc){
        if(rc != SQLITE_OK){
            cerr << desc << ": " << sqlite3_errmsg(db) << endl;
            exit(1);
        }
    };
    
    rc = sqlite3_open_v2("../Setu.db", &db, SQLITE_OPEN_READWRITE, nullptr);
    check_ok("database open failed");
    
    sqlite3_stmt *stmt;
    string zSql = "INSERT INTO Illustrations (id, extension) VALUES (?, ?)";
    rc = sqlite3_prepare_v2(db, zSql.c_str(), -1, &stmt, nullptr);
    check_ok("prepare failed");
    
    for(auto &file : fs::directory_iterator(root)){
        fs::path fileName = file.path().filename();
        int stem = stoi(fileName.stem().string().substr(1));
        string extension = fileName.extension().string().substr(1);
        string str = fileName.string();
        if(str.length() > 0 && str[0] == 'H'){
            rc = sqlite3_bind_int(stmt, 1, stem);
            check_ok("bind id failed"); 
                
            rc = sqlite3_bind_text(stmt, 2, extension.c_str(), -1, SQLITE_STATIC);
            check_ok("bind extension failed");
                
            rc = sqlite3_step(stmt);
            if(rc != SQLITE_DONE){
                cerr << "insert failed: " << sqlite3_sql(stmt) << endl;
            }
            
            rc = sqlite3_reset(stmt);
            check_ok("reset failed");
        }
    }
    
    sqlite3_finalize(stmt);
    sqlite3_close_v2(db);
    
    return 0;
}
