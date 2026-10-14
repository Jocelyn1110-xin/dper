#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc,char** argv) {
    if(argc < 5){
        cout << "usage: dper <correctSolve.exe> <otherSolve.exe> <generator.exe> <data.txt>\n";
        return 1;
    }

    const string corPath = argv[1];
    const string othPath = argv[2];
    const string genPath = argv[3];
    const string txtPath = argv[4];

    const string quote = "\"";

    const string command = quote + quote + genPath + quote + " >" + quote + txtPath + quote + quote;
    const int code = system(command.c_str());
    cout << "gen.exe exit code: " << code << '\n';

    const string corr = quote + quote + corPath + quote + " <" + quote + txtPath + quote + " >" + quote + "std.txt" + quote + quote;
    const int code1 = system(corr.c_str());
    cout << "correct solve exit code: " << code1 << '\n';

    const string othe = quote + quote + othPath + quote + " <" + quote + txtPath + quote + " >" + quote + "brute.txt" + quote + quote;
    const int code2 = system(othe.c_str());
    cout << "other solve exit code: " << code2 << '\n';

    return 0;
}