#include "runner.h"
#include <string>
#include <cstdlib>
using namespace std;

int runCommand(const string& programPath,const string& inputFile,const string& outputFile){
    const string quote = "\"";

    string command = quote + quote + programPath + quote;
    if(!inputFile.empty())command = command + " < " + quote + inputFile + quote;
    command = command + " > " + quote + outputFile + quote + quote;

    return system(command.c_str());
}