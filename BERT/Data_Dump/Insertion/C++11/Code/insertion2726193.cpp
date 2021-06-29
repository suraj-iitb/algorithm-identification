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
    rep(i,n){
        for(int j=i-1;j>=0;--j){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
            else break;
        }
        rep(j,n) cout<<a[j]<<(j==n-1?"":" ");
        cout<<endl;
    }
    return 0;
}
