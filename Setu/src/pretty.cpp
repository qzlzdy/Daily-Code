#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "sqlite3.h"

using namespace std;
namespace fs = filesystem;

int main(){
    fs::path root = "D:\\qzlzdy\\setu";
    map<int, string> suffix;
    auto getId = [](const string &name){
        return stoi(name.substr(1));
    };
    auto getName = [&](int id){
        return "H" + to_string(id);
    };
    int count = 0;
    int last = 1;
    for(auto &file: fs::directory_iterator(root)){
        fs::path filename = file.path().filename();
        string stem = filename.stem().string();
        string extension = filename.extension().string().substr(1);
        if(extension == "JPEG" || extension == "JPG" || extension == "jpeg"){
            extension = "jpg";
        }
        ++count;
        int id = getId(stem);
        suffix[id] = extension;
        if(id > last){
            last = id;
        }
    }
    int prevCount;
    ifstream prevCountFile(".prevCount");
    prevCountFile >> prevCount;
    prevCountFile.close();
    
    ofstream currCountFile(".prevCount");
    currCountFile << count;
    currCountFile.close();
    cout << "Total Number of Images: " << prevCount << " -> " << count << endl;

    ofstream logfile("ChangLog.txt");
    sqlite3 *db;
    int res;
    auto statusCheck = [&](const string &desc, int code){
        if(res != SQLITE_OK && res != SQLITE_ROW && res != SQLITE_DONE){
            cerr << desc << " (" << res << "): "
                 << sqlite3_errmsg(db) << endl;
            exit(-1);
        }
    };
    res = sqlite3_open_v2("D:\\qzlzdy\\Setu.db", &db,
                          SQLITE_OPEN_READWRITE, nullptr);
    statusCheck("Database open failed", res);
    string INSERT_SQL =
        "INSERT INTO setus(illust_id, extension) "
        "VALUES(?, ?)";
    auto insert = [&](int id, const string &ext){
        sqlite3_stmt *stmt;
        res = sqlite3_prepare_v2(db, INSERT_SQL.c_str(), INSERT_SQL.length(),
                                 &stmt, nullptr);
        statusCheck("Prepare failed", res);
        res = sqlite3_bind_int(stmt, 1, id);
        statusCheck("Bind illust_id failed", res);
        res = sqlite3_bind_text(stmt, 2, ext.c_str(), ext.length(), SQLITE_STATIC);
        statusCheck("Bind extension failed", res);
        res = sqlite3_step(stmt);
        statusCheck("Insert failed", res);
        sqlite3_finalize(stmt);
        cout << "insert H" << id << "." << ext << endl;
        logfile << "insert H" << id << "." << ext << endl;
    };
    string UPDATE_SQL =
        "UPDATE setus "
        "SET extension = ? "
        "WHERE illust_id = ? ";
    auto update = [&](int id, const string &ext){
        sqlite3_stmt *stmt;
        res = sqlite3_prepare_v2(db, UPDATE_SQL.c_str(), UPDATE_SQL.length(),
                                 &stmt, nullptr);
        statusCheck("Prepare failed", res);
        res = sqlite3_bind_text(stmt, 1, ext.c_str(), ext.length(), SQLITE_STATIC);
        statusCheck("Bind extension failed", res);
        res = sqlite3_bind_int(stmt, 2, id);
        statusCheck("Bind illust_id failed", res);
        res = sqlite3_step(stmt);
        statusCheck("Update failed", res);
        sqlite3_finalize(stmt);
        cout << "update H" << id << "." << ext << endl;
        logfile << "update H" << id << "." << ext << endl;
    };
    int cursor = 1;
    while(last > count){
        while(suffix.find(cursor) != suffix.end()){
            if(cursor > prevCount){
                insert(cursor, suffix[cursor]);
            }
            ++cursor;
        }
        fs::path old_p = root / fs::path(getName(last) + "." + suffix[last]);
        fs::path new_p = root / fs::path(getName(cursor) + "." + suffix[last]);
        fs::rename(old_p, new_p);
        if(cursor > prevCount){
            insert(cursor, suffix[last]);
        }
        else{
            update(cursor, suffix[last]);
        }
        ++cursor;
        do{
            --last;
        }while(suffix.find(last) == suffix.end());
    }
    cursor = cursor > prevCount ? cursor : prevCount + 1;
    while(cursor <= count){
        insert(cursor, suffix[cursor]);
        ++cursor;
    }
    sqlite3_close_v2(db);
    logfile.close();
    return EXIT_SUCCESS;
}
