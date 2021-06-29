#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

typedef std::pair<int, int> EDGE;

const int N = 1e5 + 1;

std::vector<EDGE> G[N];
int dis[N];

void dij(int st) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
  bool vis[N] = {false};
  dis[st] = 0;
  q.push({dis[st], st});
  while (!q.empty()) {
    auto nv = q.top();
    q.pop();
    int x = nv.second;
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto &d : G[x]) {
      int v = d.first;
      int c = d.second;
      if (dis[v] > dis[x] + c) {
        dis[v] = dis[x] + c;
        q.push({dis[v], v});
      }
    }
  }
}

int main() {
  int n, e, st;
  while (std::cin >> n >> e >> st) {
    for (int i = 0; i < N; ++i) G[i].clear();
    memset(dis, INF, sizeof(dis));
    for (int i = 0; i < e; ++i) {
      int u, v, c;
      std::cin >> u >> v >> c;
      G[u].push_back({v, c});
    }
    dij(st);
    for (int i = 0; i < n; ++i) {
      if (dis[i] == INF) {
        std::cout << "INF" << std::endl;
      } else {
        std::cout << dis[i] << std::endl;
      }
    }
  }
  return 0;
}

