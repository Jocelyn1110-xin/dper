#include "readAns.h"
#include <string>
#include <fstream>
using namespace std;

bool readAnswer(const string& path,string& out){
    ifstream in(path);
    if(!in)return false;
    if(!(in >> out))return false;
    return true;
}