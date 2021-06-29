#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)


//    Edges := 重み付き辺の集合
//    WeightedGraph := 重み付きグラフ
//    UnWeightedGraph := 重み無しグラフ
//    Matrix := 距離行列
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

//計算量 O(ElogV)
// Dijkstra(g, s): 重み付き有向グラフ g 上で,
// 頂点 s からすべての頂点への最短距離を求め, その列を返す。
//
int INF = numeric_limits<int>::max();
template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s)
{
  const auto inf = numeric_limits< T >::max();
  vector< T > dist(g.size(), inf);

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
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int v,e,r;
    cin>>v>>e>>r;
    WeightedGraph<int> g(v);
    FOR(i,0,e){
      int in1,in2,c;
      cin>>in1>>in2>>c;
      g[in1].push_back(edge<int>(in1,in2,c));
    }
    vector<int> res = dijkstra(g,r);
    FOR(i,0,res.size()){
      if(res[i]==INF) cout<<"INF"<<endl;
      else cout<<res[i]<<endl;
    }
}

