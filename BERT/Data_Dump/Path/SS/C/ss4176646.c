#include <bits/stdc++.h>
using namespace std;

#define MAX_V 100000
#define MAX_E 500000
#define INF 1e18

struct Edge {
  int to, cost;
};

class Node {
public:
  int v;
  int cost;
  Node(int v, int cost) : v(v), cost(cost) {}
  bool operator < (const Node& node) const { return cost < node.cost; }
  bool operator > (const Node& node) const { return cost > node.cost; }
};

pair<vector<long long>,vector<long long>> Dijkstra(const vector<vector<Edge>>& es, int s) {
  vector<long long> dir(MAX_V, -1);
  vector<long long> dist(MAX_V, INF);
  vector<int> visited(MAX_V, 0);
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  pq.emplace(s, 0);
  dist[s] = 0;

  while (!pq.empty()) {
    const Node node = pq.top(); pq.pop();
    int v = node.v;
    int cost = node.cost;
    if (visited[v]) continue;
    visited[v] = true;

    for (const auto& next_node : es[v]) {
      int nv = next_node.to;
      int node_cost = next_node.cost;
      if (visited[nv]) continue;
      long long next_cost = cost + node_cost;
      if (next_cost < dist[nv]) {
        dir[v] = nv;
        dist[nv] = next_cost;
        pq.emplace(nv, next_cost); // 最短経路更新出来れば更新
      }
    }
  }
  return make_pair(dist, dir);
}

int main(void) {
  int V, E, r;
  cin >> V >> E >> r;

  vector<vector<Edge>> es(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    es[s].push_back({t, d});
    // es[t].push_back({t, d});
  }

  vector<long long> dist, dir;
  tie(dist, dir) = Dijkstra(es, r);
  for (int t = 0; t < V; t++) {
    long long d = dist[t];
    if (d == INF) cout << "INF" << endl;
    else cout << d << endl;
  }

  return 0;
}
