/*
O(ElogV)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

constexpr int MAX=1<<30;
constexpr ll INF=1LL<<62;
constexpr int MOD=1e9+7;



template<typename T >
struct edge {
  int to;
  T cost;
  edge()=default;
  edge(int to, T cost) : to(to), cost(cost) {}

};


template<class T>
vector<T> dijkstra(vector< vector<edge<T>> > &g,int s,const T inf,const T zero){
    vector<T> dist(g.size(),inf);
    using pti=pair<T,int>;
    priority_queue<pti,vector<pti>,greater<pti>> que;
    dist[s]=zero;
    que.emplace(dist[s],s);
    while(!que.empty()){
      T cost;
      int idx;
      tie(cost,idx)=que.top();
      que.pop();
      if(dist[idx]<cost) continue;
      for(auto &e:g[idx]){
        auto next_cost=cost+e.cost;
        if(dist[e.to]<=next_cost) continue;
        dist[e.to]=next_cost;
        que.emplace(dist[e.to],e.to);
      }
    }
    return dist;
}

signed main(){
  int v,e,r;
  cin>>v>>e>>r;
  vector< vector<edge<ll>> > g(v);
  for(int i=0;i<e;i++){
    int s,t,d;
    cin>>s>>t>>d;
    g[s].emplace_back(t,d);
  }
  auto V=dijkstra<ll>(g,r,INF,0);
  for(int i=0;i<v;i++){
    if(V[i]==INF) cout<<"INF"<<endl;
    else cout<<V[i]<<endl;
  }
}
