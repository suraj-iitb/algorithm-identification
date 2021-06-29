#include <bits/stdc++.h>
using namespace std;

template <typename T> struct Dijkstra {
  Dijkstra(size_t size) : size(size), G(size) {}

  struct edge {
    edge(int to, T cost) : to(to), cost(cost) {}
    int to;
    T cost;
  };

  using P = pair<T, int>;
  const T inf = numeric_limits<T>::max();

  size_t size;
  vector<vector<edge>> G;
  vector<T> d;

  void add_edge(int u, int v, T c) {
    G[u].push_back(edge(v, c));
  }

  void build(int s) {
    d.assign(size, inf);
    priority_queue<P, vector<P>, greater<P>> q;

    d[s] = 0;
    q.push(P(0, s));

    while (!q.empty()) {
      P p = q.top();
      q.pop();
      int v = p.second;
      if (d[v] < p.first) continue;
      for (auto &e : G[v])
        if (d[e.to] > p.first + e.cost) {
          d[e.to] = p.first + e.cost;
          q.push(P(d[e.to], e.to));
        }
    }
  }

  T operator[](int v) {
    return d[v];
  }
};

int main() {
  int V, E, r;
  cin >> V >> E >> r;

  Dijkstra<int> G(V);
  for (int i = 0; i < E; ++i) {
    int s, t, d;
    cin >> s >> t >> d;

    G.add_edge(s, t, d);
  }

  G.build(r);

  for (int i = 0; i < V; ++i) {
    if (G[i] == G.inf) {
      cout << "INF" << endl;
    } else {
      cout << G[i] << endl;
    }
  }
}

