#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;
namespace fs = filesystem;

int main(){
#if define LINUX
    fs::path root = "/run/media/qzlzdy/Data/qzlzdy/welfare";
#else /* WINDOWS */
    fs::path root = "D:\\qzlzdy\\welfare";
#endif
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
            suffix[id] = extension.string();
            if(id > last){
                last = id;
            }
        }
    }
    ofstream ChangeLog("CHANGELOG.txt");
    ChangeLog << "[INFO] Image Number: " << count << endl;
    int cursor = 1;
    while(last > count){
        while(suffix.find(cursor) != suffix.end()){
            ++cursor;
        }
        fs::path old_p = root / fs::path(getName(last) + suffix[last]);
        fs::path new_p = root / fs::path(getName(cursor) + suffix[last]);
        fs::rename(old_p, new_p);
        ChangeLog << "[INFO] Rename " << old_p.string() << " to " << new_p.string() << endl;
        ++cursor;
        do{
            --last;
        }while(suffix.find(last) == suffix.end());
    }
    ChangeLog.close();
    return 0;
}
