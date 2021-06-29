#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Graph {
  priority_queue< pii >q;
  long long *dist;
  bool *sptSet;
  vector<pii> *G;
 public:
  Graph(int V);
  void addEdge(int v, int w, int d);
  void dijkstra(int V, int src);
};

Graph::Graph(int V) {
  dist = new long long[V];
  sptSet = new bool [V];
  G = new vector<pii> [V];
}

void Graph::addEdge(int v, int w, int d) {
  G[v].push_back({w, d});
}

void Graph::dijkstra(int V, int src) {
  for (int i = 0; i < V; i++)
    dist[i] = 1e18, sptSet[i] = false;
  dist[src] = 0;
  q.push({0, src});

  while (!q.empty()) {
    int u = q.top().second;
    // printf("%dqwe\n", u);
    q.pop();
    if (sptSet[u])
      continue;
    sptSet[u] = true;
    for (vector<pii>::iterator it = G[u].begin(); it != G[u].end(); ++it) {
      int v = it->first, w = it->second;
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        q.push({ -dist[v], v});
      }
    }
  }
  for (int i = 0; i < V; i++) {
    if (dist[i] < 1e18)
      cout << dist[i] << "\n";
    else
      cout << "INF\n";
  }
}


int main() {
  int V, E, R, s, t, d;
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> V >> E >> R;
  Graph G(V);
  for (int i = 0; i < E; i++) {
    std::cin >> s >> t >> d;
    G.addEdge(s, t, d);
  }
  G.dijkstra(V, R);
  return 0;
}
