#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "runner.h"
#include "parseCnt.h"
#include "readAns.h"
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
    const int cnt = parseCount(argv[5]);
    if(cnt == 0){
        cout << "count ERROR!\n";
        return 1;
    }

    for(int i = 1;i <= cnt; i++){

        int code = runCommand(genPath, "", txtPath);
        if(code){
            cout << "round " << i << ": gen.exe failed (exit code " << code << ")\n";
            return 1;
        }

        code = runCommand(corPath, txtPath, "std.txt");
        if(code){
            cout << "round " << i << ": std.exe failed (exit code " << code << ")\n";
            return 1;
        }

        code = runCommand(othPath, txtPath, "brute.txt");
        if(code){
            cout << "round " << i << ": brute.exe failed (exit code " << code << ")\n";
            return 1;
        }

        cout << i << " : ";

        string s1;
        if(!readAnswer("std.txt",s1)){
            cout << "ERROR: can't read std.txt\n";
            return 1;
        }
        cout << "std = " << s1 << "; ";

        string s2;
        if(!readAnswer("brute.txt",s2)){
            cout << "ERROR: can't read brute.txt\n";
            return 1;
        }
        cout << "brute = " << s2 << "  ";
        
        if(s1==s2)cout << "MATCH!\n";
        else {
            cout << "MISMATCH!\n";
            return 2;
        }
    }
    cout << "All " << cnt << " sets of data have passed!\n";

    return 0;
}