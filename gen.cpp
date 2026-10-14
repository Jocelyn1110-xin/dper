#include <iostream>
#include <random>
using namespace std;

int main(){

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(1,1200);
    int n = dist(rng);

    cout<<n<<'\n';
    for(int i=0;i<n;i++){
        random_device a;
        mt19937 t(a());
        uniform_int_distribution<int> dis(-100,100);
        cout<<dis(t)<<' ';
    }
    cout<<'\n';
    return 0;
}