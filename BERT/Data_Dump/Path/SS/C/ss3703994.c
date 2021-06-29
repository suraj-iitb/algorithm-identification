#include <cstddef>
#include <cstdint>
#include <vector>

namespace null_null {

using i32 = std::int_fast32_t;
using i64 = std::int_fast64_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;
using usize = std::size_t;

constexpr usize operator"" _z(unsigned long long x) noexcept {
  return static_cast<usize>(x);
}

template <typename T>
std::vector<T> make_v(usize a) { return std::vector<T>(a); }
template <typename T, typename... Ts>
auto make_v(usize a, Ts... ts) {
  return std::vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template <typename T, typename V>
typename std::enable_if<std::is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template <typename T, typename V>
typename std ::enable_if<std::is_class<T>::value != 0>::type
fill_v(T &t, const V &v) {
  for (auto &e : t) fill_v(e, v);
}

template <typename T, typename V>
inline void chmin(T &a, V b) {
  if (a > b) a = b;
}
template <typename T, typename V>
inline void chmax(T &a, V b) {
  if (a < b) a = b;
}

} // namespace null_null

namespace graph {

struct base_edge {
  std::size_t from;
  std::size_t to;
  base_edge(std::size_t from, std::size_t to) : from(from), to(to) {}
};

template <class T>
struct edge : public base_edge {
  T val;
  edge(std::size_t from, std::size_t to, T v) : base_edge(from, to), val(v) {}
};

template <>
struct edge<void> : public base_edge {
  edge(int from, int to) : base_edge(from, to) {}
};
template <class C>
struct maxflow_edge : public base_edge {
  C cap;
  std::size_t rev;
  maxflow_edge(int from, int to, C cap, std::size_t rev)
      : base_edge(from, to), cap(cap), rev(rev) {}
};

template <class T>
struct directed_graph : public std::vector<std::vector<edge<T>>> {
  directed_graph(std::size_t n) : std::vector<std::vector<edge<T>>>(n) {}
  void add_edge(const edge<T> &e) { this->at(e.from).push_back(e); }
};

template <class T>
struct undirected_graph : public std::vector<std::vector<edge<T>>> {
  undirected_graph(std::size_t n) : std::vector<std::vector<edge<T>>>(n) {}
  void add_edge(const edge<T> &e) {
    this->at(e.from).push_back(e);
    edge<T> re = e;
    std::swap(re.from, re.to);
    this->at(e.to).push_back(re);
  }
};

template <class C>
struct maxflow_graph : public std::vector<std::vector<maxflow_edge<C>>> {
  maxflow_graph(std::size_t n) : std::vector<std::vector<maxflow_edge<C>>>(n) {}
  void add_edge(int from, int to, C cap, std::size_t rev_cap = 0) {
    this->at(from).push_back(
        maxflow_edge<C>(from, to, cap, this->at(to).size()));
    this->at(to).push_back(
        maxflow_edge<C>(to, from, rev_cap, this->at(from).size() - 1));
  }
};

} // namespace graph

#include <limits>
#include <queue>

namespace graph {

template <class T>
std::vector<T> dijkstra(const graph::directed_graph<T> &g, std::size_t s) {
  const T INF = std::numeric_limits<T>::max();
  const T ZERO = T();
  const std::size_t n = g.size();

  struct node {
    T dist;
    std::size_t vertex;
    node(T d, std::size_t v) : dist(d), vertex(v) {}
    bool operator<(const node &n) const { return n.dist < dist; }
  };

  std::vector<T> dist(n, INF);
  std::priority_queue<node> que;

  dist[s] = ZERO;
  que.emplace(dist[s], s);

  while (!que.empty()) {
    node p = que.top();
    T d = p.dist;
    std::size_t v = p.vertex;
    que.pop();
    if (dist[v] < d)
      continue;
    for (const auto &e : g[v]) {
      if (dist[v] + e.val < dist[e.to]) {
        dist[e.to] = dist[v] + e.val;
        que.emplace(dist[e.to], e.to);
      }
    }
  }
  return std::move(dist);
}

} // namespace graph

#include <algorithm>
#include <iostream>
#include <utility>

namespace null_null {

void main_() {
  usize V, E, r;
  std::cin >> V >> E >> r;

  graph::directed_graph<usize> g(V);
  for (usize i = 0; i < E; i++) {
    usize s, t, d;
    std::cin >> s >> t >> d;
    g.add_edge({s, t, d});
  }

  auto dist = graph::dijkstra(g, r);

  for (usize i = 0; i < V; i++) {
    if (dist[i] == std::numeric_limits<usize>::max()) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << dist[i] << std::endl;
    }
  }
}

} // namespace null_null

int main() {
  null_null::main_();
  return 0;
}

