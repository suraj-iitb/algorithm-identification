#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;
vector<int> dist;
const int INF = 1e9;
struct  edge{int to, cost;};
vector<edge> G[100010];

void dij(int start){
  priority_queue<P, vector<P>, greater<P> > que;
  for(int i = 0; i < dist.size(); i++){
    dist[i] = INF;
  }
  dist[start] = 0;
  que.push(P(0, start));
  
  while(!que.empty()){
    P p = que.top(); que.pop();
    int next = p.second;
    if(dist[next] < p.first) continue;
    for(int i = 0; i < G[next].size(); i++){
      edge e = G[next][i];
      if(dist[next] + e.cost < dist[e.to]){
        dist[e.to] = dist[next] + e.cost;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
}

signed main(){
  int V, E, r; cin >> V >> E >> r;
  for(int i = 0; i < E; i++){
    int s, t, d; cin >> s >> t >> d;
    edge e = {t, d}; G[s].push_back(e);
  }
  dist.resize(V, INF);
  dij(r);
  for(int i = 0; i < V; i++){
    if(dist[i] == INF) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }
}

