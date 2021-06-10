#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <utility>
using namespace std;

using ll = long long;
using p = pair<int, int>;

constexpr int inf = INT_MAX >> 1;

class edge{
public:
  int to, weight;
  edge(int t, int w){
    to = t; weight = w;
  }
};

class graph{
public:
  vector<vector<edge>> g;
  int n;

  graph(int n){
    this-> n = n;
    g.resize(n); 
  }

  void init(int e){
    for(int i=0; i<e; i++){
      int s, t, d;
      cin >> s >> t >> d;
      g[s].push_back({t, d});
    }
  }

  void dijkstra(int s){
    ll dis[n];
    for(int i=0; i<n; i++) dis[i] = inf;
                                                       
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, s});
    dis[s] = 0;

    while(!pq.empty()){
      auto f = pq.top(); pq.pop();
                                                       
      for(int i=0; i<g[f.second].size(); i++){
        int next = g[f.second][i].to;
        ll nd = dis[f.second] + g[f.second][i].weight;
        
        if(nd > dis[next]) continue;
        else{
          dis[next] = nd;
          pq.push({nd, next});
        }
      }
    }
    
    for(int i=0; i<n; i++){
      if(dis[i] == inf) cout << "INF" << endl;
      else cout << dis[i] << endl;
    }
  }

  void dijkstra(int s, int e){
    ll dis[n];
    for(int i=0; i<n; i++) dis[i] = INT_MAX >> 1;

    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, s});
    dis[s] = 0;
    
    while(!pq.empty()){
      auto f = pq.top(); pq.pop();
      if(f.second == e){
        cout << dis[e] << endl;
        return;
      } 

      for(int i=0; i<g[f.second].size(); i++){
        int next = g[f.second][i].to;
        ll nd = dis[f.second] + g[f.second][i].weight;
        
        if(nd > dis[next]) continue;
        else{
          dis[next] = nd;
          pq.push({nd, next});
        }
      }
    }
  }
};

int main(){
  int v, e, s; 
  cin >> v >> e >> s;

  graph g(v);
  g.init(e);

  g.dijkstra(s); 

  return 0;
}

