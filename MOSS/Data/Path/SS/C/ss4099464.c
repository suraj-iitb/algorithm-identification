#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
constexpr i64 inf = 1LL<<60;

template<class T>
bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

struct edge{
  int to;
  i64 cost;
  edge(){}
  edge(int t,i64 c):to(t),cost(c){}
};
using graph = vector<vector<edge>>;

vector<i64> dijkstra(graph const& adj,int v,int r){
  vector<i64> dist(v,inf);
  using pl = pair<i64,int>;
  priority_queue<pl,vector<pl>,greater<>> que;
  que.emplace(0,r);
  while(!que.empty()){
    i64 c;
    int n;
    tie(c,n) = que.top();
    que.pop();
    if(chmin(dist[n],c))
      for(auto const& nx:adj[n])
        if(dist[nx.to]==inf)
          que.emplace(c+nx.cost,nx.to);
  }
  return dist;
}

signed main(){

  int v,e,r;
  cin>>v>>e>>r;
  graph g(v);
  for(int i=0;i<e;++i){
    int s,t;
    i64 d;
    cin>>s>>t>>d;
    g[s].emplace_back(t,d);
  }

  auto dist = dijkstra(g,v,r);

  for(auto const& res:dist){
    if(res==inf)cout<<"INF"<<endl;
    else cout<<res<<endl;
  }

}
