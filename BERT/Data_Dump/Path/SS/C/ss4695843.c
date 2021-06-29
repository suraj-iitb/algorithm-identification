#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using int64 = long long;

template <class T>
using binary_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T>
class graph {
 public:
  graph(int n) : n_(n) { data_.resize(n_); }
  struct edge {
    int from, to;
    T cost;
  };
  int n_;
  std::vector<std::vector<int>> data_;
  std::vector<edge> edges_;

  virtual void add(int from, int to, T cost) = 0;
};

template <class T>
class forest : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  forest(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    assert(id < n_ - 1);
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.push_back({from, to, cost});
  }
};

template <class T>
class digraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  digraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    data_[from].emplace_back(id);
    edges_.push_back({from, to, cost});
  }

  digraph<T> reverse() const {
    digraph<T> rev(n_);
    for (auto& e : edges_) {
      rev.add(e.to, e.from, e.cost);
    }
    return rev;
  }
};

template <class T>
class undigraph : public graph<T> {
 public:
  using graph<T>::n_;
  using graph<T>::data_;
  using graph<T>::edges_;

  undigraph(int n) : graph<T>(n) {}

  void add(int from, int to, T cost = 1) {
    int id = edges_.size();
    data_[from].emplace_back(id);
    data_[to].emplace_back(id);
    edges_.push_back({from, to, cost});
  }
};

template <class T>
std::vector<T> desopo_pape(const graph<T>& g, int s) {
  std::vector<T> dist(g.n_, std::numeric_limits<T>::max());
  dist[s] = 0;
  std::vector<int> m(g.n_, 2);
  std::deque<int> dq;
  dq.emplace_back(s);
  std::vector<int> p(g.n_, -1);

  while (!dq.empty()) {
    int cur = dq.front(); dq.pop_front();
    m[cur] = 0;
    for (int id : g.data_[cur]) {
      auto& e = g.edges_[id];
      int nxt = e.from ^ e.to ^ cur;
      if (dist[nxt] > dist[cur] + e.cost) {
        dist[nxt] = dist[cur] + e.cost;
        p[nxt] = cur;
        if (m[nxt] == 2) {
          m[nxt] = 1;
          dq.emplace_back(nxt);
        } else if (m[nxt] == 0) {
          m[nxt] = 1;
          dq.emplace_front(nxt);
        }
      }
    }
  }
  std::replace(dist.begin(), dist.end(), std::numeric_limits<T>::max(), -1);
  
  return dist;
}
/*
template <class _Tp>
std::vector<_Tp> dijkstra(const graph<_Tp>& g, int s) {
  assert(0 <= s && s < g.n_);
  std::vector<_Tp> dist(g.n_, std::numeric_limits<_Tp>::max());
  binary_heap<std::pair<_Tp, int>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (dist[v] < d) continue;
    for (int id : g.data_[v]) {
      auto& e = g.edges_[id];
      int nxt = e.from ^ e.to ^ v;
      if (dist[nxt] > dist[v] + e.cost) {
        dist[nxt] = dist[v] + e.cost;
        pq.emplace(dist[nxt], nxt);
      }
    }
  }
  std::replace(dist.begin(), dist.end(), std::numeric_limits<_Tp>::max(), -1);
  return dist;
}
*/
void GRL_1_A() {
  int n, m, r; cin >> n >> m >> r;
  digraph<int> g(n);
  for (int i = 0; i < m; ++i) {
    int s, t, d; cin >> s >> t >> d;
    g.add(s, t, d);
  }

  vector<int> dist = desopo_pape(g, r);

  for (int e : dist) {
    if (e == -1) {
      cout << "INF" << '\n';
    } else {
      cout << e << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  GRL_1_A();

  return 0;
}

