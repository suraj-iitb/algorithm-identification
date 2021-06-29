#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 998244353;


int main(){
  ll n;cin>>n;
  vll a(n);
  rep(i,0,n)cin>>a[i];
  rep(i,1,n){
    rep(k,0,n-1)cout<<a[k]<<" ";
    cout<<a[n-1]<<endl;
    ll tmp=a[i];
    ll j=i-1;
    while(j>=0&&a[j]>tmp){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=tmp;
  }
  rep(k,0,n-1)cout<<a[k]<<" ";
  cout<<a[n-1]<<endl;
}




