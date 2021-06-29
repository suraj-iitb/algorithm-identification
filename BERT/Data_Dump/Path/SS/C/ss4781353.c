#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
constexpr ll INF=1LL<<60;

//始点をインデックスとして，距離と終点を持つ配列
vector<vector<pair<ll,ll>>> edge;
ll v,e,r;
vector<ll> dijkstra(ll start)
{
  vector<ll> dist(v,INF);
  dist[start]=0;
  //各点までの距離とその点自身が欲しい
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,
    greater<pair<ll,ll>>> pq;
  pq.push({dist[start],start});
  while(!pq.empty())
  {
    auto p=pq.top();
    pq.pop();
    ll d=p.first,from=p.second;
    if(dist[from]<d) continue;
    for(const auto& next: edge[from]) 
    {
      ll to=next.first,cost=next.second;
      if(dist[to]>dist[from]+cost)
      {
        dist[to]=dist[from]+cost;
        pq.push({dist[to],to});
      }
    }
  }
  return dist;
}

int main()
{
  cin>>v>>e>>r;
  edge.resize(v);
  for (int i = 0; i < e; ++i)
  {
    ll s,t,d;
    cin>>s>>t>>d;
    edge[s].push_back({t,d});
  }
  auto dist=dijkstra(r);

  for (int i = 0; i < v; ++i)
  {
    if(dist[i]==INF) cout<<"INF"<<endl;
    else cout<<dist[i]<<endl;
  }
}
