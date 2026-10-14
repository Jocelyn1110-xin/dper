#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int>a(n);
    int c_max,f_max;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    c_max=0;
    f_max=-0x3f3f3f;
    for(int i=0;i<n;i++){
        c_max+=a[i];
        c_max=max(a[i],c_max);
        f_max=max(f_max,c_max);
    }
    cout<<f_max<<'\n';
    return 0;
}