#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define lfs <<fixed<<setprecision(10)<<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
template<typename T>
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
struct edge {
  ll to,cost;
  edge(ll x,ll y):to(x),cost(y){};
};
vector<vector<ll>> WarshallFloyd(vector<vector<edge>>g){
  ll n=g.size();
  vector<vector<ll>>ret(n,vector<ll>(n,INF));
  for(ll i=0;i<n;i++){
    ret[i][i]=0;
    for(ll j=0;j<g[i].size();j++){
      ret[i][g[i][j].to]=g[i][j].cost;
    }
  }
  for(ll j=0;j<n;j++){
    for(ll i=0;i<n;i++){
      for(ll o=0;o<n;o++){
        if(ret[i][j]!=INF&&ret[j][o]!=INF){
          chmin(ret[i][o],ret[i][j]+ret[j][o]);
        }
      }
    }
  }
  return ret;
} 
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<vector<struct edge>>g(n);  
  rep(i,0,m){
    ll u,v,c;cin>>u>>v>>c;
    g[u].EB(v,c);
  }
  auto mat=WarshallFloyd(g);
  rep(i,0,n)if(mat[i][i]<0){
    cout<<"NEGATIVE CYCLE"<<endl;
    return 0;
  }
  rep(i,0,n){
    rep(j,0,n){
      if(j!=0)cout<<" ";
      if(mat[i][j]==INF)cout<<"INF";
      else cout<<mat[i][j];
    }
    cout<<endl;
  }
  return 0;
}
