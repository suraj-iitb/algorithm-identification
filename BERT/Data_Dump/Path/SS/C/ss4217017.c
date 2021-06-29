#include <bits/stdc++.h>
using namespace std;
typedef pair<int64_t,int64_t> pii;

const int64_t INF = 1e16;
struct edge{ int64_t to, d; };

 
int main(){ 
  int64_t V, E, r;
  cin >> V >> E >> r;

  vector<vector<edge>> G(100010);
  for(int i=0; i<E; i++){
    int64_t s, t, d; cin >> s >> t >> d;
    G[s].push_back(edge{t,d});
  }

  priority_queue<pii, vector<pii>, greater<pii>> Q;
  vector<int64_t> dist(100010, INF);
  dist[r] = 0; Q.push(pii(0,r));

  while(!Q.empty()){
    int64_t cur_d = Q.top().first;
    int64_t cur_v = Q.top().second;
    Q.pop();

    if(cur_d > dist[cur_v]) continue;
  
    for(int i=0; i<G[cur_v].size(); i++){
      edge e = G[cur_v][i];
      if(dist[e.to] > dist[cur_v] + e.d){
        dist[e.to] = dist[cur_v] + e.d;
       Q.push(pii(cur_d + e.d, e.to));
      }
    }

  }

  for(int i=0; i<V; i++){
    if(dist[i] == INF) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }
  
}
