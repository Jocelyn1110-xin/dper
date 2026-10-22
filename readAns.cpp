#include "readAns.h"
#include <string>
#include <fstream>
using namespace std;

bool readAnswer(const string& path,string& out){
    out.clear();
    ifstream in(path);
    if(!in)return false;
    string tok;
    bool hasAny = false;
    int k = 0;
    while(in >> tok){
        if(!hasAny && tok != "")hasAny = true;
        if(k == 0){
            out += tok;
            k = 1;
        }
        else out += " " + tok;
    }
    return hasAny;
}