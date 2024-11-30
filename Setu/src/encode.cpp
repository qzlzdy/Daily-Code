#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
namespace fs = filesystem;

int main(){
    int idx;
    ifstream CountFile(".prevCount");
    CountFile >> idx;
    CountFile.close();
    fs::path root = "D:\\Pictures\\setu";
    for(auto &file: fs::directory_iterator(root)){
        fs::path filename = file.path().filename();
        string stem = filename.stem().string();
        string extension = filename.extension().string();
        if(stem.front() != 'H'){
            fs::path oldname = root / filename;
            fs::path newname =
                root / fs::path("H" + to_string(++idx) + extension);
            fs::rename(oldname, newname);
            cout << "mv " << oldname.string()
                 << " " << newname.string() << endl;
        }
    }
    return EXIT_SUCCESS;
}
