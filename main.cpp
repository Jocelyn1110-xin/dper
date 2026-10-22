#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int runCommand(const string& programPath,const string& inputFile,const string& outputFile){
    const string quote = "\"";

    string command = quote + quote + programPath + quote;
    if(!inputFile.empty())command = command + " < " + quote + inputFile + quote;
    command = command + " > " + quote + outputFile + quote + quote;

    return system(command.c_str());
}

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

    for(int i = 1;i <= cnt; i++){

        if(runCommand(genPath, "", txtPath)){
            cout << "round " << i << ": gen.exe failed (exit code 1)\n";
            return 1;
        }
        if(runCommand(corPath, txtPath, "std.txt")){
            cout << "round " << i << ": std.exe failed (exit code 1)\n";
            return 1;
        }
        if(runCommand(othPath, txtPath, "brute.txt")){
            cout << "round " << i << ": brute.exe failed (exit code 1)\n";
            return 1;
        }

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
    cout << "All " << cnt << " sets of data have passed!\n";

    return 0;
}