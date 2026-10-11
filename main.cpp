#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc,char** argv) {
    if(argc < 3){
        cout << "usage: dper <generator.exe> <output.txt>\n";
        return 1;
    }

    const string genPath = argv[1];
    const string txtPath = argv[2];

    const string quote = "\"";
    const string command ="\"" + quote + genPath + "\"" + " >" + "\"" + txtPath + "\"" + quote;

    const int code = system(command.c_str());

    cout << "gen.exe exit code: " << code << '\n';
    return 0;
}