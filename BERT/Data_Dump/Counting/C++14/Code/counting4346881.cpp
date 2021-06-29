#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    vector<ll> a(n),b(n),c(10001);
    rep(i,n) cin>>a[i];
    rep(i,n) c[a[i]]++;
    rep(i,10000) c[i+1]+=c[i];
    for(ll i=n-1; i>=0; i--){
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    rep(i,n){
        if(i==0) cout<<b[i];
        else cout<<' '<<b[i];
    }
    cout<<endl;
    return 0;
}
