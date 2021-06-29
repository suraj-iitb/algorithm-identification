#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P; typedef pair<Int,Int> Pl;
const int mod = 1e9+7;
const int INF32 = numeric_limits<int>::max();
const Int INF64 = numeric_limits<Int>::max();
double const PI = acos(-1);
#define END {cout<<(ans)<<'\n'; return 0;}
#define ALL(vec) vec.begin(),vec.end()
#define Pr(type) priority_queue<type>
#define gPr(type) priority_queue<type,vector<type>,greater<type>>
#define V(type) vector<type>
#define rep(i,n) for(int i=0; i<n; i++)
#define rer(i,s,n) for(int i=s; i<n; i++)
#define gnr(i,l,r) for(int i=r; i>=l; i--)
#define eb emplace_back
#define fi first
#define se second
#define pri1(a) cout<<a<<'\n'
#define pri2(a,n) rep(i,(n)-1)cout<<a[i]<<' '; cout<<a[(n)-1]<<'\n';
#define prip(p) cout<<(p).first<<' '<<(p).second<<'\n'
template<class T> inline bool cmin(T& a, T b) { if (a > b) { return a = b; } return false; }
template<class T> inline bool cmax(T& a, T b) { if (a < b) { return a = b; } return false; }

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

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
vector< T > bellman_ford(Edges< T > &edges, int V, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(V, INF);
  dist[s] = 0;
  for(int i = 0; i < V - 1; i++) {
    for(auto &e : edges) {
      if(dist[e.src] == INF) continue;
      dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
    }
  }
  for(auto &e : edges) {
    if(dist[e.src] == INF) continue;
    if(dist[e.src] + e.cost < dist[e.to]) return vector< T >();
  }
  return dist;
}

int n,m,q,_,x,y;
string s,sb;
bool ok;
char ch;

int main(){
  cin.tie(nullptr); ios::sync_with_stdio(0);

  cin>>n>>m; Edges<int>ed;
  rep(i,m){
    cin>>x>>y>>q; ed.eb(x,y,q);
  }
  V(int)ans[n];
  rep(i,n){
    auto b=bellman_ford(ed,n,i);
    if(b.empty()){pri1("NEGATIVE CYCLE"); return 0;}
    ans[i]=b;
  }
  rep(i,n){
    rep(j,n){
      if(ans[i][j]==INF32)cout<<"INF";
      else cout<<ans[i][j];
      cout<<(j==n-1?'\n':' ');
    }
  }
}
