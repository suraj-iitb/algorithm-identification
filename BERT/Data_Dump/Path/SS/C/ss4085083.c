#line 1 "test/aoj/GRL_1_A.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#line 1 "test/aoj/../../graph/template.cpp"
#include <vector>

template< typename T >
struct Edge {
  int from, to;
  T cost;
  Edge() {}
  Edge(int f, int t) : from(f), to(t), cost(1) {}
  Edge(int f, int t, T c) : from(f), to(t), cost(c) {}
  friend bool operator < (const Edge& lhs, const Edge& rhs) { return lhs.cost < rhs.cost; };
  friend bool operator > (const Edge& lhs, const Edge& rhs) { return rhs < lhs; };
  friend bool operator <= (const Edge& lhs, const Edge& rhs) { return !(lhs > rhs); };
  friend bool operator >= (const Edge& lhs, const Edge& rhs) { return !(lhs < rhs); };
};

template< typename T >
using Edges = std::vector< Edge< T > >;
template< typename T >
using Graph = std::vector< Edges< T > >;
#line 2 "test/aoj/../../graph/dijkstra.cpp"

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template < typename T >
struct Dijkstra {
  using P = std::pair<T, int>; // <始点からの距離, 点のid>
  const T INF; // 十分に大きいがoverflowしない値として、型Tの最大値の半分を使う
  const int V; // 頂点数
  Graph<T> g;
  std::vector<T> dist; // 始点からの距離
  std::vector<bool> visit; // すでに探索済みの点か
  Dijkstra(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V), visit(V) {}
  Dijkstra(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V), visit(V) {}
  void init(int s) {
    std::fill(dist.begin(), dist.end(), INF);
    std::fill(visit.begin(), visit.end(), false);
    dist[s] = T(); // 始点の距離を0で初期化
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({dist[s], s});
    while (!pq.empty()) {
      P node = pq.top(); pq.pop();
      int from = node.second;
      if (visit[from]) continue;
      visit[from] = true;
      for (auto &e : g[from]) {
        if (visit[e.to]) continue;
        T d = node.first + e.cost;
        if (d >= dist[e.to]) continue;
        dist[e.to] = d;
        pq.push({d, e.to});
      }
    }
  }
};
#line 3 "test/aoj/GRL_1_A.test.cpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E, root;
  cin >> V >> E >> root;
  Graph<ll> g(V);
  for (int i = 0; i < E; ++i) {
    int x, y;
    ll d;
    cin >> x >> y >> d;
    g[x].emplace_back(x, y, d);
  }
  Dijkstra<ll> di(g);
  di.init(root);
  for (int i = 0; i < V; ++i) {
    if (di.dist[i] == di.INF) cout << "INF" << endl;
    else cout << di.dist[i] << endl;
  }
}

