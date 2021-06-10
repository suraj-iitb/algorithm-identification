#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<queue>
#include<tuple>

using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)

template<typename T>
struct Edge{
  int to;
  T cost;
};

template<typename T>
vector<T> dijkstra(vector<vector<Edge<T>>> &g, int s){
  const auto inf=numeric_limits<T>::max();
  vector<T> dist(g.size(), inf);
  dist[s]=0;
  priority_queue<pair<T, int>> q;
  q.push({-dist[s], s});
  while(q.size()>0){
    T cost; int u;
    tie(cost, u)=q.top(); q.pop();
    cost*=-1;
    for(auto e: g[u]){
      if(cost+e.cost<dist[e.to]){
        dist[e.to]=cost+e.cost;
        q.push({-dist[e.to], e.to});
      }
    }
  }
  return dist;
}

int main(){

  int n, m, s; cin>> n>> m>> s;
  using edge=Edge<int>;
  vector<vector<edge>> g(n);
  rep(_, m){
    int a, b, c; cin>> a>> b>> c;
    g[a].push_back(edge{b, c});
  }

  auto dist=dijkstra(g, s);
  for(auto d: dist){
    if(d==numeric_limits<int>::max()) cout<< "INF"<< endl;
    else cout<< d<< endl;
  }

  return 0;
}

