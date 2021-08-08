#include <filesystem>
#include <iostream>
#include <string>

using namespace std;
namespace fs = filesystem;

int main(int argc, char **argv){
    if(argc != 2){
        cerr << "Usage: " << argv[0] << " min_code" << endl;
        return 1;
    }
    int idx = atoi(argv[1]);
    fs::path root = "D:\\qzlzdy\\setu";
    for(auto &file : fs::directory_iterator(root)){
        fs::path filename = file.path().filename();
        string stem = filename.stem().string();
        string extension = filename.extension().string();
        switch(stem.front()){
        case 'G':
        case 'V':
            break;
        case 'H':
            if(stem[1] == '0'){
                fs::remove(root / filename);
                cout << "remove file " << filename.string() << endl;
            }
            break;
        default:{
            fs::path oldname = root / filename;
            fs::path newname =
                root / fs::path("H" + to_string(idx++) + extension);
            fs::rename(oldname, newname);
            cout << "rename " << oldname.string()
                 << " as " << newname.string() << endl;
            break;
        }
        }
    }
    return 0;
}