#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c_max;
    int f_max=-0x3f3f3f;
    for(int i=0;i<n;i++){
        c_max=a[i];
        f_max=max(c_max,f_max);
        for(int j=i+1;j<n;j++){
            c_max+=a[j];
            f_max=max(c_max,f_max);
        }
    }
    cout<<f_max<<'\n';
    return 0;
}