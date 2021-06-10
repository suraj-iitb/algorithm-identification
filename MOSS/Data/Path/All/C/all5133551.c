#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
const ll mod = 998244353;
//const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

int main() {
  /* mod は 1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll n,m;
  cin>>n>>m;
  ll dp[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        dp[i][j]=0;
      }
      else{
        dp[i][j]=inf;
      }
    }
  }
  for(int i=0;i<m;i++){
    ll x,y,d;
    cin>>x>>y>>d;
    chmin(dp[x][y],d);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        chmin(dp[j][k],dp[j][i]+dp[i][k]);
      }
    }
  }
  for(int i=0;i<n;i++){
    if(dp[i][i]<0){
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(dp[i][j]<=inf/2){
        cout<<dp[i][j];
      }
      else{
        cout<<"INF";
      }
      if(j!=n-1){
        cout<<" ";
      }
    }
    cout<<endl;
  }
}
