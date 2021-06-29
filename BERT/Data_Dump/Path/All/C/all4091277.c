#line 1 "test/aoj/GRL_1_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
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
#line 2 "test/aoj/../../graph/warshall-floyd.cpp"

#include <limits>
#include <vector>
// #include <iostream>

template < typename T >
struct WarshallFloyd {
  const T INF; // 十分に大きいがoverflowしない値として、型Tの最大値の半分を使う
  const int V; // 頂点数
  Graph<T> g;
  std::vector<std::vector<T>> dist;
  WarshallFloyd(Graph<T> &g): INF(std::numeric_limits<T>::max()/2), V(g.size()), g(g), dist(V, std::vector<T>(V, INF)) { init(); }
  WarshallFloyd(Graph<T> &g, int V): INF(std::numeric_limits<T>::max()/2), V(V), g(g), dist(V, std::vector<T>(V, INF)) { init(); }
  void init() {
    for (int i = 0; i < V; ++i) {
      dist[i][i] = 0;
      for (auto &e: g[i]) dist[i][e.to] = e.cost;
    }
    for (int k = 0; k < V; ++k) {
      for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
          if (dist[i][k] == INF || dist[k][j] == INF) continue;
          T d = dist[i][k]+dist[k][j];
          if (dist[i][j] > d) {
            // std::cout << i << j << k << " " << d << std::endl;
            dist[i][j] = d;
          }
        }
      }
    }
  }
  bool has_negative_cycle() {
    for (int i = 0; i < V; ++i) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }
};
#line 3 "test/aoj/GRL_1_C.test.cpp"

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int V, E;
  cin >> V >> E;
  Graph<ll> g(V);
  for (int i = 0; i < E; ++i) {
    int x, y; ll d;
    cin >> x >> y >> d;
    g[x].emplace_back(x, y, d);
  }
  WarshallFloyd<ll> wf(g);
  if (wf.has_negative_cycle()) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (j > 0) cout << " ";
      if (wf.dist[i][j] == wf.INF) cout << "INF";
      else cout << wf.dist[i][j];
    }
    cout << endl;
  }
}

