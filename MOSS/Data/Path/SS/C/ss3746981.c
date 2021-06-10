#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

const int kMaxV = 100010;
const int kInf = 0x3F3F3F3F;

using namespace std;

struct Edge {
  int from;
  int to;
  int dist;

  Edge(int from, int to, int dist): from(from), to(to), dist(dist) {}
};

struct HeapNode {
  int d, u;

  HeapNode(int d, int u): d(d), u(u) {}
  bool operator < (const HeapNode & rhs) const {
    return d > rhs.d;
  }
};

struct Dijkstra {
  int v, e;
  vector<Edge> edges;
  vector<int> g[kMaxV];
  int dist[kMaxV];
  int parent[kMaxV];

  Dijkstra(int v): v(v) {}

  void AddEdge(int from, int to, int dist) {
    edges.emplace_back(from, to, dist);
    g[from].push_back(edges.size() - 1);
  }

  void Solve(int source) {
    for (int i = 0; i < v; ++i) {
      dist[i] = kInf;
    }
    dist[source] = 0;
    bool done[kMaxV] = {false};
    priority_queue<HeapNode> q;
    q.emplace(0, source);
    while (!q.empty()) {
      auto x = q.top();
      q.pop();
      if (done[x.u]) {
        continue;
      }
      done[x.u] = true;
      for (auto e_num: g[x.u]) {
         auto e = edges[e_num];
         if (dist[e.to] > dist[e.from] + e.dist) {
           dist[e.to] = dist[e.from] + e.dist;
           parent[e.to] = e.from;
           q.emplace(dist[e.to], e.to);
         }
      }
    }
  }
};

int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);
  auto solver = new Dijkstra(v);
    for (int i = 0; i < e; ++i) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    solver->AddEdge(s, t, d);
  }
  solver->Solve(r);
  for (int i = 0; i < v; ++i) {
    if (solver->dist[i] == kInf) {
      printf("INF\n");
    } else {
      printf("%d\n", solver->dist[i]);
    }
  }
}

