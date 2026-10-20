#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int trans(string str){
    int cnt = 0;
    for(int i = 0;i < str.length(); i++){
        cnt = cnt * 10 + (str[i] - '0');
    }
    return cnt;
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
    const string count = argv[5];
    const int cnt = trans(count);

    const string quote = "\"";

    for(int i = 1;i <= cnt; i++){
        const string command = quote + quote + genPath + quote + " >" + quote + txtPath + quote + quote;
        const int code = system(command.c_str());
        //cout << "gen.exe exit code: " << code << '\n';

        const string corr = quote + quote + corPath + quote + " <" + quote + txtPath + quote + " >" + quote + "std.txt" + quote + quote;
        const int code1 = system(corr.c_str());
        //cout << "correct solve exit code: " << code1 << '\n';

        const string othe = quote + quote + othPath + quote + " <" + quote + txtPath + quote + " >" + quote + "brute.txt" + quote + quote;
        const int code2 = system(othe.c_str());
        //cout << "other solve exit code: " << code2 << '\n';

        cout << i << " : ";

        ifstream in1("std.txt");
        if(!in1){
            cout << "ERROR!\n";
            break;
        }
        string s1;
        in1 >> s1;
        cout << "std = " << s1 << "; ";
        ifstream in2("brute.txt");
        if(!in2){
            cout << "ERROR!\n";
            break;
        }
        string s2;
        in2 >> s2;
        cout << "brute = " << s2 << "  ";
        
        if(s1==s2)cout << "MATCH!\n";
        else {
            cout << "MISMATCH!\n";
            break;
        }
    }

    return 0;
}