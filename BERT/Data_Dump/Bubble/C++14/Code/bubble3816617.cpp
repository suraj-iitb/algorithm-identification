#include <bits/stdc++.h>
using namespace std;
#define rep(i,n,x) for(int i=n;i<x;i++)
#define rem(i,n,x) for(int i=n;i>=x;i--)

int main() {
    int n; cin>>n;
    vector<int> a(n); rep(i,0,n) cin>>a[i];

    int sw = 0;
    bool flag = 1;
    for(int i = 0; flag; i++){
        flag = 0;
        rem(j,n-1,i+1){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                sw++;
                flag = 1;
            }
        }
    }

    rep(i,0,n){
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sw<<endl;

    return 0;
}
