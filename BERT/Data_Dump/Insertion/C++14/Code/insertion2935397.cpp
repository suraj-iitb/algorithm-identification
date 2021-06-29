#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

int main(){
    int n; cin>>n;
    int a[n]; rep(i,n) cin>>a[i];
    rep(i,n){
        cout<<a[i]<<(n-1-i?" ":"\n");
    }
    for(int i=1;i<n;i++){
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        rep(i,n){
            cout<<a[i]<<(n-1-i?" ":"\n");
        }
    }

    return 0;
}

