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
    rep(i,n){
        ll v=a[i];
        ll j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            a[j]=v;
            j--;
        }
        a[j+1]=v;
        rep(k,n){
            cout<<a[k];
            if(k<n-1) cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
