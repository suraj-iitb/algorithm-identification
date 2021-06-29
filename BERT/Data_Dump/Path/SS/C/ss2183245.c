#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

constexpr auto Infinity = numeric_limits<long long>::max() / 2;
using pii = pair<int, int>;

vector<long long> dijkstra(vector<vector<pii>> const& graph, int start) {
  using pii = pair<int, int>;
  size_t const n_vertex = graph.size();
  vector<long long> dist(n_vertex, Infinity);
  dist[start] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pque;
  pque.emplace(0, start);
  while (!pque.empty()) {
    int v, d;
    tie(d, v) = pque.top();
    pque.pop();
    if (d > dist[v]) continue;
    for (auto&& e : graph[v]) {
      int cost, destination;
      tie(cost, destination) = e;
      if (dist[destination] > d + cost) {
        dist[destination] = d + cost;
        pque.emplace(d + cost, destination);
      }
    }
  }
  return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, e, r;
  cin >> v >> e >> r;
  vector<vector<pii>> graph(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    graph[s].emplace_back(d, t);
  }
  auto const& dists = dijkstra(graph, r);
  for (auto i : dists) {
    if (i == Infinity)
      cout << "INF" << endl;
    else
      cout << i << endl;
  }
}
