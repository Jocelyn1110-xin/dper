#include "parseCnt.h"
#include <string>
using namespace std;

int parseCount(const string& count){
    long long ans = 0;
    for(int i = 0;i < (int)count.length(); i++){
        if(count[i] >= '0' && count[i] <= '9')ans = ans * 10 + (count[i] - '0');
        else return 0;

        if(ans > 1000000)return 0;
    }
    return (int)ans;
}