#include <bits/stdc++.h>
using namespace std;

char readchar() {
  static char buf[1 << 15], *ptr = buf, *end = buf;
  if (ptr == end) ptr = buf, end = buf + fread(buf, 1, 1 << 15, stdin);
  return *ptr++;
}
void writechar(char c = 0) {
  static char buf[1 << 15], *ptr = buf;
  if (ptr == end(buf) or c == 0) fwrite(buf, 1, ptr - buf, stdout), ptr = buf;
  *ptr++ = c;
}
template <class Z = int> Z getint() {
  char c = readchar();
  bool neg = c == '-';
  Z res = neg ? 0 : c - '0';
  while (isdigit(c = readchar())) res = res * 10 + (c - '0');
  return neg ? -res : res;
}
template <class Z> void putint(Z a, char delim = '\n') {
  if (a < 0) writechar('-'), a = -a;
  int d[40], i = 0;
  do d[i++] = a % 10; while (a /= 10);
  while (i--) writechar('0' + d[i]);
  writechar(delim);
}
string getstring(char delim = '\n') {
  string res;
  for (char c; (c = readchar()) != delim; ) res += c;
  return res;
}
void putstring(string s, char delim = '\n') {
  for (char c : s) writechar(c);
  writechar(delim);
}

template <class T> struct digraph {
  struct edge {
    int id, from, to;
    T w;
  };
  const int n;
  vector<int> head;
  vector<edge> edges, g;
  digraph(int _n = 0) : n(_n), head(n + 1) {}
  void add(int from, int to, T w = 1) {
    edges.push_back({(int)edges.size(), from, to, w});
    ++head[from];
  }
  void build() {
    partial_sum(begin(head), end(head), begin(head));
    g.resize(head[n]);
    for (auto&& e : edges) g[--head[e.from]] = e;
  }
  template <class F> void for_each_edge(int v, F f) const {
    for (int i = head[v]; i < head[v + 1]; ++i) f(g[i]);
  }
};

template <class Key, class T> struct radix_heap {
  static_assert(is_integral<Key>::value, "");
  array<vector<pair<Key, T>>, sizeof(Key) * 8 + 1> v;
  Key last = 0;
  size_t sz = 0, ptr = 0;
  static int lg(Key a) { return a ? __lg(a) : -1; }
  void emplace(Key key, T val) {
    assert(key >= last);
    v[lg(key ^ last) + 1].emplace_back(key, val);
    ++sz;
  }
  void pull() {
    if (ptr < v[0].size()) return;
    v[0].clear(), ptr = 0;
    int i = 1;
    while (v[i].empty()) ++i;
    last = min_element(begin(v[i]), end(v[i]), [](auto a, auto b) {
      return a.first < b.first;
    })->first;
    for (auto e : v[i]) v[lg(e.first ^ last) + 1].push_back(e);
    v[i].clear();
  }
  pair<Key, T> top() { return pull(), v[0][ptr]; }
  void pop() { pull(), --sz, ++ptr; }
  bool empty() const { return sz == 0; }
};

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

template <class T> vector<T> dijkstra(const digraph<T>& g, int s) {
  vector<T> d(g.n, inf<T>);
  radix_heap<T, int> rh;
  rh.emplace(d[s] = 0, s);
  while (not rh.empty()) {
    T dv;
    int v;
    tie(dv, v) = rh.top(), rh.pop();
    if (dv != d[v]) continue;
    g.for_each_edge(v, [&](auto&& e) {
      if (chmin(d[e.to], dv + e.w)) rh.emplace(d[e.to], e.to);
    });
  }
  return d;
}

int main() {
  int n = getint(), m = getint(), s = getint();
  digraph<int> g(n);
  while (m--) {
    int u = getint(), v = getint(), w = getint();
    g.add(u, v, w);
  }
  g.build();
  for (auto e : dijkstra(g, s)) {
    if (e < inf<int>) {
      putint(e);
    } else {
      putstring("INF");
    }
  }
  writechar();
}

