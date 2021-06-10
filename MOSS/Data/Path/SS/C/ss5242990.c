#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int INF = (1e9);

vector<int> dijkstra(vector< vector< pair<int,int> > > &G, int s){
  vector<int> ret(G.size(),INF);
  priority_queue< pair<int,int> > wait;
  wait.emplace(0,s);
  while(!wait.empty()){
    int c = -wait.top().first, v = wait.top().second;
    wait.pop();
    if(ret[v] < c) continue;
    ret[v] = c;
    for(size_t i = 0; i < G[v].size(); ++i){
      int c_ = c + G[v][i].first, v_ = G[v][i].second;
      if(c_ < ret[v_]){
        ret[v_] = c_;
        wait.emplace(-c_,v_);
      }
    }
  }
  return ret;
}

int main(){
  int V, E, r;
  cin >> V >> E >> r;
  vector< vector< pair<int,int> > > G(V);
  for(int i = 0; i < E; ++i){
    int s, t, d;
    cin >> s >> t >> d;
    G[s].emplace_back(d,t);
  }
  vector<int> ans = dijkstra(G,r);
  for(int i = 0; i < V; ++i){
    if(ans[i] < INF) cout << ans[i] << endl;
    else cout << "INF" << endl;
  }
  return 0;
}

