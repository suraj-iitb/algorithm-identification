#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll res=0;
    rep(i,n){
        ll minj=i;
        for(ll j=i; j<n; j++){
            if(a[j]<a[minj]) {minj=j;}
        }
        if(minj!=i){swap(a[i],a[minj]); res++;}
    }
    rep(i,n){cout<<a[i]; if(i<n-1) cout<<' ';}
    cout<<endl;
    cout<<res<<endl;
    return 0;
}
