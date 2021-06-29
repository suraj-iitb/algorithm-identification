#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const long long LINF = 1000000000000000018ll;

struct Edge {
  int dst;
  long long cost;
  Edge() {}
  Edge(int x, int y) : dst(x), cost(y) {}
};

vector<vector<Edge> > graph;

vector<long long> dijkstra(int start_v, int v) {
  vector<long long> dist(v, 1000000000000000018ll);
  dist[start_v] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
    greater<pair<long long, int> > > q;

  q.push(make_pair(0, start_v));

  while (!q.empty()) {
    pair<long long, int> t = q.top(); q.pop();
    int cur_v = t.second;
    for (int i = 0; i < graph[cur_v].size(); i++) {
      int next_v = graph[cur_v][i].dst;
      long long cost = graph[cur_v][i].cost;
      if (dist[next_v] > dist[cur_v] + cost) {
        dist[next_v] = dist[cur_v] + cost;
        q.push(make_pair(dist[next_v], next_v));
      }
    }
  }
  return dist;
}

int main () {
  int v, e, r;
  cin >> v >> e >> r;

  graph.assign(v, vector<Edge>());
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    graph[s].push_back(Edge(t, d));
  }

  vector<long long> dist = dijkstra(r, v);
  for (int i = 0; i < v; i++) {
    if ( dist[i] == LINF ) {
      cout << "INF" << "\n";
    } else {
      cout << dist[i] << "\n";
    }
  }
  return 0;
}
