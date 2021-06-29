#include <bits/stdc++.h>
using namespace std;

// ダイクストラ法
// 負の辺を持たないこと。

//#define UNDIRECTED // 無向グラフ
// #define GET_PATH // 最短経路

constexpr int MAX_V = 1e5;
constexpr int INF = 1e9 + 7;

using P = pair<int, int>; // ソートを考慮して(コスト,頂点)

struct Edge {
  int to;
  int cost;
};

int V;
vector<Edge> graph[MAX_V];
array<int, MAX_V> dist;
#ifdef GET_PATH
int prevv[MAX_V];
#endif

void dijkstra(int s) {
#ifdef GET_PATH
  fill_n(prevv, MAX_V, -1);
#endif
  fill_n(dist.begin(), MAX_V, INF);
  dist[s] = 0;

  priority_queue<P, vector<P>, greater<P>> que;
  que.push({dist[s], s});

  while (!que.empty()) {
    P p{que.top()};
    que.pop();
    int from{p.second};
    if (dist[from] < p.first)
      continue;
    for (size_t i{}; i < graph[from].size(); ++i) {
      Edge e{graph[from][i]};
      if (dist[e.to] > dist[from] + e.cost) {
        dist[e.to] = dist[from] + e.cost;
        que.push({dist[e.to], e.to});
#ifdef GET_PATH
        prevv[e.to] = from;
#endif
      }
    }
  }
}

#ifdef GET_PATH
vector<int> get_path(int t) {
  vector<int> path;
  while (t >= 0) {
    path.push_back(t);
    t = prevv[t];
  }
  reverse(path.begin(), path.end());
  return path;
}
#endif

int main() {
  int E, s;
  cin >> V >> E >> s;
  for (int i{}; i < E; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back({to, cost});
#ifdef UNDIRECTED
    graph[to].push_back({from, cost});
#endif
  }

  dijkstra(s);

  for (int i{}; i < V; ++i) {
    cout << (dist[i] < INF ? to_string(dist[i]) : "INF") << endl;
  }

#ifdef GET_PATH
  for (int i{}; i < V; ++i) {
    vector<int> path = get_path(i);
    for (int j{}; j < path.size(); ++j) {
      cout << (j > 0 ? " " : "") << path[j];
    }
    cout << endl;
  }
#endif

  return 0;
}

