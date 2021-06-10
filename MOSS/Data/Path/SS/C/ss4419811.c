#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

struct edge{
  int to, cost;
};
using namespace std;
const int INF=2e9;

int main(){
  int V, E, r;
  cin >> V >> E >> r;
  vector< vector<edge> > G(V);
  rep(i,E){
    int s, t, d;
    cin >> s >> t >> d;
    edge e;
    e.to=t, e.cost=d;
    G[s].push_back(e);
  }
  vector<int> dist(V);
  rep(i,V) dist[i]=INF;
  dist[r]=0;
  priority_queue< int, vector<int>, greater<int> > q;
  q.push(r);
  while(!q.empty()){
    int n=q.top(); q.pop();
    rep(i,G[n].size()){
      int next=G[n][i].to;
      int new_dist=dist[n]+G[n][i].cost;
      if(dist[next]<=new_dist) continue;
      q.push(next);
      dist[next]=new_dist;
    }
  }
  rep(i,V){
    if(dist[i]==INF) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }

  return 0;
}

