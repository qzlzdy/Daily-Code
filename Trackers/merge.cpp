#include <fstream>

using namespace std;

int main(){
    char buf;
    ofstream outfile("trackers.txt");
    {
        ifstream infile("trackerslist/trackers_all.txt");
        while(infile >> noskipws >> buf){
            outfile << buf;
        }
        infile.close();
    }
    {
        ifstream infile("TrackersListCollection/all.txt");
        while(infile >> noskipws >> buf){
            outfile << buf;
        }
        infile.close();
    }
    outfile.close();
    return 0;
}
