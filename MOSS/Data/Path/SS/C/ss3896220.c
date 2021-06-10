#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

using namespace std;
using ll = long long;

template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T> constexpr T INF = numeric_limits<T>::max() / 2;

template <typename T> struct edge {
  int src, to;
  T cost;
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
  operator int() const { return to; }
};

template <typename T> using Edges = vector<edge<T>>;
template <typename T> using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T> using Matrix = vector<vector<T>>;

template <typename T> vector<T> dijkstra(WeightedGraph<T> &g, int s) {
  vector<T> dist(g.size(), INF<T>);

  using Pi = pair<T, int>;
  priority_queue<Pi, vector<Pi>, greater<Pi>> que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while (!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if (dist[idx] < cost)
      continue;
    for (auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if (dist[e.to] <= next_cost)
        continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int V, E, r;
  cin >> V >> E >> r;
  WeightedGraph<int> G(V);
  REP(i, E) {
    int s, t, d;
    cin >> s >> t >> d;
    G.at(s).emplace_back(t, d);
  }
  for (auto dist : dijkstra(G, r)) {
    if (dist == INF<int>) {
      cout << "INF\n";
    } else {
      cout << dist << '\n';
    }
  }

  return 0;
}
