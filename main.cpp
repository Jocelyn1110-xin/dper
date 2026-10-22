#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int isValidCount_(const string& count){
    long long ans = 0;
    for(int i = 0;i < (int)count.length(); i++){
        if(count[i] >= '0' && count[i] <= '9')ans = ans * 10 + (count[i] - '0');
        else return 0;

        if(ans > 1000000)return 0;
    }
    return (int)ans;
}

bool readAnswer(const string& path,string& out){
    ifstream in(path);
    if(!in)return false;
    if(!(in >> out))return false;
    return true;
}

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
    const int cnt = isValidCount_(argv[5]);
    if(cnt == 0){
        cout << "count ERROR!\n";
        return 1;
    }

    for(int i = 1;i <= cnt; i++){

        int code;

        code = runCommand(genPath, "", txtPath);
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
            cout << "ERROR!\n";
            return 1;
        }
        cout << "std = " << s1 << "; ";

        string s2;
        if(!readAnswer("brute.txt",s2)){
            cout << "ERROR\n";
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