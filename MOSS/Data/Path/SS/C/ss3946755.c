#pragma GCC optimize ("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P; typedef pair<Int,Int> Pl;
const int mod = 1e9+7;
static constexpr Int Inf = numeric_limits<Int>::max();
#define END {cout<<ans<<'\n'; return 0;}
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define mp make_pair
#define Pr(t) priority_queue<t>
#define gPr(t) priority_queue<t,vector<t>,greater<t>>
#define V(t) vector<t>
#define rep(i,n) for(int(i)=0; i<n; i++)
#define rer(i,l,r) for(int i=l; i<=r; i++)
#define gnr(i,l,r) for(int i=r; i>=l; i--)
#define eb emplace_back
#define pri1(a) cout<<(a)<<'\n'
#define pri2(a,n) {rep(pri2i,n-1)cout<<a[pri2i]<<' '; cout<<a[n-1]<<'\n';}
#define prip(p) cout<<p.fi<<' '<<p.se<<'\n'
template<class T> inline bool cmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool cmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n,m,_,x,y,q;
string s,sb;
bool ok;
char ch;

template< typename T >
struct edge {
  int src, to;
  T w;

  edge(int to, T w) : src(-1), to(to), w(w) {}

  edge(int src, int to, T w) : src(src), to(to), w(w) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.w;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}


int main(){
  cin.tie(nullptr); ios::sync_with_stdio(false);

  cin>>n>>m>>q; WeightedGraph<int>g(n);
  rep(i,m){
    cin>>x>>y>>_; g[x].eb(y,_);
  }
  auto ans=dijkstra(g,q);
  rep(i,n){
    if(ans[i]>1e9)pri1("INF"); else pri1(ans[i]);
  }
  /*rep(i,m)rep(j,m){
    cin>>x;
    if(i!=j)g[i].eb(j,x);
  }
  V(int)buf=dijkstra(g,0);
  pri1(1);*/
  /*V(int)grp[3];
  rep(i,n)rep(j,n){
    cin>>x;
    grp[(i+j)%3].eb(x);
  }
  Int ans=1e18,cost;
  rep(i,m)for(int j=0; j!=i&&j<m; j++)for(int k=0; k!=i&&k!=j&&k<m; k++){
    cost=0;
    for(int e:grp[0])cost+=d[e][i];
    for(int e:grp[1])cost+=d[e][j];
    for(int e:grp[2])cost+=d[e][k];
    cmin(ans,cost);
  }
  END*/
}
