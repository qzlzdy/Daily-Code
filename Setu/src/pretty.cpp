#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

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
    for(auto &file : fs::directory_iterator(root)){
        fs::path fileName = file.path().filename();
        fs::path stem = fileName.stem();
        fs::path extension = fileName.extension();
        if(extension != ".gif" && extension != ".mp4"){
            ++count;
            int id = getId(stem.string());
            suffix[id] = extension.string().substr(1);
            if(id > last){
                last = id;
            }
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
    
    ofstream ChangeLog("update.sql");
    int cursor = 1;
    auto emitSql = [&](const string &sql){
        ChangeLog << sql << endl;
        cout << sql << endl;
    };
    while(last > count){
        while(suffix.find(cursor) != suffix.end()){
            if(cursor > prevCount){
                ostringstream sql;
                sql << "INSERT INTO Illustrations (id, extension) "
                    << "VALUES (" << cursor << ", '" << suffix[last] << "');";
                emitSql(sql.str());
            }
            ++cursor;
        }
        fs::path old_p = root / fs::path(getName(last) + "." + suffix[last]);
        fs::path new_p = root / fs::path(getName(cursor) + "." + suffix[last]);
        fs::rename(old_p, new_p);
        if(cursor > prevCount){
            ostringstream sql;
            sql << "INSERT INTO Illustrations (id, extension) "
                << "VALUES (" << cursor << ", '" << suffix[last] << "');";
            emitSql(sql.str());
        }
        else{
            ostringstream sql;
            sql << "UPDATE Illustrations "
                << "SET extension = '" << suffix[last] << "' "
                << "WHERE id = " << cursor << ";" << endl;
            emitSql(sql.str());
            sql.str("");
            sql << "DELETE FROM have "
                << "WHERE illust_id = " << cursor << ";" << endl;
            emitSql(sql.str());
        }
        ++cursor;
        do{
            --last;
        }while(suffix.find(last) == suffix.end());
    }
    cursor = cursor > prevCount ? cursor : prevCount + 1;
    while(cursor <= count){
        ostringstream sql;
        sql << "INSERT INTO Illustrations (id, extension) "
            << "VALUES (" << cursor << ", '" << suffix[last] << "');";
        emitSql(sql.str());
        ++cursor;
    }
    ChangeLog.close();
    return 0;
}
