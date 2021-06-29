#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n,m;
vector<pll> G[100005];
ll dist[100005];

void dijikstra(ll s){
  fill(dist,dist+n,LINF);
  dist[s]=0;
  priority_queue<pll, vector<pll>, greater<pll>> q;
  q.emplace(0,s);
  while(!q.empty()){
    pll v=q.top(); q.pop();
    if(dist[v.second]<v.first) continue;
    for(auto nv: G[v.second]){
      if(dist[nv.first]>dist[v.second]+nv.second){
        dist[nv.first]=dist[v.second]+nv.second;
        q.emplace(dist[nv.first],nv.first);
      }
    }
  }
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll r; cin>>n>>m>>r;
  rep(i,m){
    ll a,b,c; cin>>a>>b>>c;
    G[a].emplace_back(b,c);
  }
  dijikstra(r);
  rep(i,n){
    if(dist[i]!=LINF) cout<<dist[i]<<endl;
    else cout<<"INF"<<endl;
  }
}
