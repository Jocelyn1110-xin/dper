#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc,char** argv) {
    if(argc < 2){
        cout << "usage: dper <generator.exe>\n";
        return 1;
    }

    const string genPath = argv[1];

    const string command = "\"" + genPath +"\"" + " > out1.txt";

    const int code = system(command.c_str());

    cout << "gen.exe exit code: " << code << '\n';
    return 0;
}