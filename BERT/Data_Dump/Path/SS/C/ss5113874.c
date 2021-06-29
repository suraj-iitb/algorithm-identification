#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,int>;
const ll INF=1LL<<60;

struct Edge{
  ll to;
  ll cost;
  Edge(ll t,ll c) : to(t),cost(c){}
};

using Graph=vector<vector<Edge>>;

void dijkstra(const Graph &G,int s,vector<ll> &dis){
  int N=G.size();
  dis.resize(N,INF);
  priority_queue<P,vector<P>,greater<P>> pq;
  dis[s]=0;
  pq.emplace(dis[s],s);
  while(!pq.empty()){
    P p=pq.top();
    pq.pop();
    int v=p.second;
    if(dis[v]<p.first){
      continue;
    }
    for(auto &e : G[v]){
      if(dis[e.to]>dis[v]+e.cost){
        dis[e.to]=dis[v]+e.cost;
        pq.emplace(dis[e.to],e.to);
      }
    }
  }
}

int main(){
  int v,e,r;
  cin >> v >> e >> r;
  Graph G(v);
  for(int i=0;i<e;++i){
    ll s,t,d;
    cin >> s >> t >> d;
    G[s].push_back(Edge(t,d));
  }
  vector<ll> dis;
  dijkstra(G,r,dis);

  for(int i=0;i<v;++i){
    if(dis[i]==INF){
      cout << "INF" << endl;
      continue;
    }
    cout << dis[i] << endl;
  }

  return 0;
}

