#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// const ll INF = 1LL << 60;

vector<int> dijkstra(int s, vector<vector<pair<int, int>>>& g){
  int n = g.size();
  vector<int> dist(n, INF);
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0,s});
  while(!pq.empty()){
    int d, v;
    tie(d, v) = pq.top(); pq.pop();
    if(dist[v] < d) continue;
    for(auto e : g[v]){
      int nv, w;
      tie(nv, w) = e;
      if(dist[v] + w < dist[nv]){
        dist[nv] = dist[v] + w;
        pq.push({dist[nv], nv});
      }
    }
  }
  return dist;
}
int main(){
  int V, E, r;
  cin >> V >> E >> r;
  vector<vector<pair<int, int>>> g(V);
  REP(i, E){
    int s, t, d;
    cin >> s >> t >> d;
    g[s].push_back({t, d});
  }
  vector<int> ans = dijkstra(r, g);
  REP(i, V){
    if(ans[i] == INF){
      cout << "INF" << endl;
    }
    else{
      cout << ans[i] << endl;   
    }
  }
  return 0;
}


