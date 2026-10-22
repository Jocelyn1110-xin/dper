#include "readAns.h"
#include <string>
#include <fstream>

bool readAnswer(const string& path,string& out){
    ifstream in(path);
    if(!in)return false;
    if(!(in >> out))return false;
    return true;
}