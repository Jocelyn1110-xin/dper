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
    while(in >> tok){
        if(hasAny)out += " ";
        out += tok;
        hasAny = true;
    }
    return hasAny;
}