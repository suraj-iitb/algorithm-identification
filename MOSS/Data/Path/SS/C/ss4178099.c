#line 1 "test/radix_heap.aoj.test.cpp"
#define PROBLEM                                                                \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#line 1 "data_structure/radix_heap.cpp"
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <utility>
#include <vector>

template <class T> class radix_heap {
  using size_t = std::size_t;
  using u64 = std::uint_fast64_t;
  using V = std::pair<u64, T>;

public:
  using key_type = u64;
  using mapped_type = T;
  using value_type = V;

private:
  static size_t log2p1(const u64 x) {
    if (x == 0)
      return 0;
    else
      return 64 - __builtin_clzll(x);
  }

  std::vector<std::vector<V>> u;
  u64 last;

public:
  radix_heap() : u(), last(0) {}

  void push(const V x) {
    assert(last <= x.first);

    const size_t i = log2p1(x.first ^ last);
    if (u.size() <= i)
      u.resize(i + 1);
    u[i].push_back(x);
  }
  V pop() {
    if (u[0].empty()) {
      size_t i = 1;
      while (u[i].empty())
        i += 1;
      last = std::numeric_limits<u64>::max();
      for (const V &e : u[i])
        last = std::min(last, e.first);
      for (const V &e : u[i])
        u[log2p1(e.first ^ last)].push_back(e);
      u[i].clear();
    }
    V ret = u[0].back();
    u[0].pop_back();
    return ret;
  }
};
#line 5 "test/radix_heap.aoj.test.cpp"

#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <tuple>

int main() {
  int n, m, r;
  std::cin >> n >> m >> r;
  std::vector<std::vector<std::pair<int, int>>> g(n);
  for (int i = 0; i != m; i += 1) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g[s].emplace_back(d, t);
  }
  constexpr int Inf = std::numeric_limits<int>::max();
  std::vector<int> dist(n, Inf);
  dist[r] = 0;
  radix_heap<int> heap;
  int size = 0;
  heap.push({0, r});
  size += 1;
  while (size != 0) {
    int c, v;
    std::tie(c, v) = heap.pop();
    size -= 1;
    if (dist[v] < c)
      continue;
    int d, u;
    for (const auto &e : g[v]) {
      std::tie(d, u) = e;
      if (c + d < dist[u]) {
        dist[u] = c + d;
        heap.push({dist[u], u});
        size += 1;
      }
    }
  }
  for (int i = 0; i != n; i += 1) {
    if (dist[i] < Inf)
      std::cout << dist[i];
    else
      std::cout << "INF";
    std::cout << std::endl;
  }
}

