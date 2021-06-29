#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 100000000000000000
#define MAX 100010
using namespace std;

struct edge{
  int to;
  ll cost;
};

typedef pair<ll, int> p;
ll dist[MAX];
vector<edge> graph[MAX];

void dijkstra(int r){
  priority_queue<p, vector<p>, greater<p> > que;
  bool color[MAX];
  for(int i = 0; i < MAX; i++){
    dist[i] = INF;
    color[i] = false;
  }
  dist[r] = 0;
  que.push(p(0, r));
  while(!que.empty()){
    p f = que.top(); que.pop();
    int v = f.second;
    color[v] = true;
    if(dist[v] < f.first) continue;
    for(int i = 0; i < graph[v].size(); i++){
      edge e = graph[v][i];
      if(color[e.to] == true) continue;
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        que.push(p(dist[e.to], e.to));
      }
    }
  }
}

int main(){
  int v, e, r;
  cin >> v >> e >> r;
  for(int i = 0; i < e; i++){
    int s, t, d;
    cin >> s >> t >> d;
    graph[s].push_back((edge){t, d});
    //graph[t].push_back((edge){s, d});
  }
  dijkstra(r);
  for(int i = 0; i < v; i++){
    if(dist[i] == INF){
      cout << "INF" << endl;
    }else{
      cout << dist[i] << endl;
    }
  }
  return 0;
}
