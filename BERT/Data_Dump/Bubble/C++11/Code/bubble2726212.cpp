#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int a[101];
int main(){
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    int cnt=0;
    while(1){
        bool flag=true;
        rep(i,n-1)if(a[i]>a[i+1]) swap(a[i],a[i+1]),flag=false,++cnt;
        if(flag) break;
    }
    rep(i,n) cout<<a[i]<<(i==n-1?"":" ");
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}
