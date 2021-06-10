#include <iostream>
#include <vector>
#include <queue>

const long long LINF = 1LL<<60;

struct Edge {
  int to;
  long long w;
  Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = std::vector<std::vector<Edge>>;

int main() {
  int N, M, r;
  std::cin >> N >> M >> r;

  Graph G(N);
  for (int j = 0; j < M; ++j) {
    int s, t;
    long long d;
    std::cin >> s >> t >> d;
    G[s].push_back(Edge(t, d));
  }

  std::vector<long long> dist(N, LINF);

  using qval = std::pair<long long, int>;
  std::priority_queue<qval, std::vector<qval>, std::greater<qval>> pque;

  dist[r] = 0;
  pque.push(std::make_pair(dist[r], r));

  while (!pque.empty()) {
    int v = pque.top().second;
    long long d = pque.top().first;
    pque.pop();

    // dist[v] < d はゴミを意味する
    if (dist[v] < d)
      continue;

    // 選択されたノードから出ている辺を緩和する
    for (auto &e : G[v]) {
      int nv = e.to;
      long long w = e.w;
      if (dist[v] + w < dist[nv]) {
        dist[nv] = dist[v] + w;
        pque.push(std::make_pair(dist[nv], nv));
      }
    }
  }

  for (int v = 0; v < N; ++v) {
    if (dist[v] == LINF)
      std::cout << "INF" << std::endl;
    else
      std::cout << dist[v] << std::endl;
  }
}

