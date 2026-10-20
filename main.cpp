#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc,char** argv) {
    if(argc < 6){
        cout << "usage: dper <correctSolve.exe> <otherSolve.exe> <generator.exe> <data.txt> count\n";
        return 1;
    }

    const string corPath = argv[1];
    const string othPath = argv[2];
    const string genPath = argv[3];
    const string txtPath = argv[4];
    const int cnt = stoi(argv[5]);

    const string quote = "\"";

    for(int i = 1;i <= cnt; i++){
        const string command = quote + quote + genPath + quote + " >" + quote + txtPath + quote + quote;
        system(command.c_str());

        const string corr = quote + quote + corPath + quote + " <" + quote + txtPath + quote + " >" + quote + "std.txt" + quote + quote;
        system(corr.c_str());

        const string othe = quote + quote + othPath + quote + " <" + quote + txtPath + quote + " >" + quote + "brute.txt" + quote + quote;
        system(othe.c_str());

        cout << i << " : ";

        ifstream in1("std.txt");
        if(!in1){
            cout << "ERROR!\n";
            return 1;
        }
        string s1;
        in1 >> s1;
        cout << "std = " << s1 << "; ";
        ifstream in2("brute.txt");
        if(!in2){
            cout << "ERROR!\n";
            return 1;
        }
        string s2;
        in2 >> s2;
        cout << "brute = " << s2 << "  ";
        
        if(s1==s2)cout << "MATCH!\n";
        else {
            cout << "MISMATCH!\n";
            return 2;
        }
    }

    return 0;
}