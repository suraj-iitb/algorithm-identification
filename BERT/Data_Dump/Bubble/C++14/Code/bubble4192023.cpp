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
    bool flag=true;
    ll res=0;
    while(flag){
        flag=false;
        rep(i,n-1){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                flag=true;
                res++;
            }
        }
    }
    rep(i,n) {cout<<a[i]; if(i<n-1) cout<<' ';}
    cout<<endl;
    cout<<res<<endl;
    return 0;
}
