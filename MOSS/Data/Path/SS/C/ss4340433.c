#include <iostream>
#include <queue>
#include <vector>

struct Edge {
  int dst;
  long long cost;
  Edge() {}
  Edge(int x, long long y) : dst(x), cost(y) {}
};

std::vector<long long> dijkstra(int sv, std::vector<std::vector<Edge>> &G) {
  const long long LINF = 1000000000000000018LL;

  int n = (int)G.size();
  std::vector<long long> dist(n, LINF);
  dist[sv] = 0;

  typedef std::pair<long long, int> PLI;
  std::priority_queue<PLI, std::vector<PLI>, std::greater<PLI>> que;

  que.push(std::make_pair(0LL, sv));

  while (!que.empty()) {
    PLI now = que.top();
    que.pop();
    long long cur_d = now.first;
    long long cur_v = now.second;

    if (dist[cur_v] < cur_d) {
      continue;
    }

    for (int i = 0; i < (int)G[cur_v].size(); i++) {
      int next_v = G[cur_v][i].dst;
      long long cost = G[cur_v][i].cost;
      if (dist[cur_v] + cost < dist[next_v]) {
        dist[next_v] = dist[cur_v] + cost;
        que.push(std::make_pair(dist[next_v], next_v));
      }
    }
  }
  return dist;
}

int main() {
  const long long LINF = 1000000000000000018LL;
  int v, e, r;
  std::cin >> v >> e >> r;

  std::vector<std::vector<Edge>> g(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g[s].push_back(Edge(t, d));
  }

  std::vector<long long> dist = dijkstra(r, g);
  for (int i = 0; i < v; i++) {
    if (dist[i] == LINF) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << dist[i] << std::endl;
    }
  }
  return 0;
}
