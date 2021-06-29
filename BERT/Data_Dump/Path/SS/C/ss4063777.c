#include <vector>
#include <utility>
#include <queue>
#include <tuple>
//#include <boost/optional.hpp>
//using boost::optional;
//auto const none = boost::none;

struct None {} none;
template<class T> struct optional {
  bool b; T t;
  optional() : b(false), t() {}
  optional(None rhs) : b(false), t() { (void)rhs; }
  optional(T t) : b(true), t(t) {}
  explicit operator bool() const { return b; }
  T& operator*() { return t; }
  auto& operator=(None rhs) { (void)rhs; b=false; return *this; }
  auto& operator=(T const& rhs) { b=true; t = rhs; return *this; }
};



// unweighted graph
struct Graph {
  using size_t = std::size_t;
  size_t n; std::vector<std::vector<size_t>> dat;
  Graph() {}
  Graph(size_t n) : n(n), dat(n) {}
  auto& operator[](size_t i) { return dat[i]; }
  auto begin() { return dat.begin(); }
  auto end() { return dat.end(); }
  void de(size_t i, size_t j) { dat[i].push_back(j); }
  void e(size_t i, size_t j) { de(i, j); de(j, i); }
};

// adjacency list (weighted graph)
template<class T> struct GraphL {
  using size_t = std::size_t;
  struct E {
    size_t to; T w;
    E(size_t to) : to(to), w() {}
    E(size_t to, T w) : to(to), w(w) {}
  };
  size_t n; std::vector<std::vector<E>> dat;
  GraphL() {}
  GraphL(size_t n) : n(n), dat(n) {}
  auto& operator[](size_t i) { return dat[i]; }
  auto begin() { return dat.begin(); }
  auto end() { return dat.end(); }
  size_t size() const { return n; }
  void de(size_t i, size_t j, T t) { dat[i].push_back(E(j, t)); }
  void e(size_t i, size_t j, T t) { de(i, j, t); de(j, i, t); }
};

template<class U, class T, class F=std::plus<>> auto dijkstra(GraphL<T> g, std::size_t s, U u, F f=F()) {
  using pr = std::pair<U, std::size_t>;
  std::vector<optional<U>> r(g.size());
  std::priority_queue<pr, std::vector<pr>, std::greater<>> que;
  que.emplace(*(r[s]=u), s);
  while(!que.empty()) {
    U w; std::size_t v; std::tie(w, v) = que.top(); que.pop();
    if(r[v] && *r[v] < w) continue;
    for(auto const& e : g[v]) {
      U nw = f(w, e.w);
      if(!r[e.to] || nw < *r[e.to]) que.emplace(*(r[e.to]=nw), e.to);
    }
  }
  return r;
}



#include <iostream>

void GRL_1_A() {
  using namespace std;
  size_t N, M, r;
  cin >> N >> M >> r;
  GraphL<long long> g(N);
  for(size_t i=0;i<M;++i) {
    size_t s, t; long long d;
    cin >> s >> t >> d;
    g.de(s, t, d);
  }
  auto d = dijkstra(g, r, 0LL);
  for(auto& r : d) if(r) cout << *r << '\n'; else cout << "INF\n";
}

signed main() {

  GRL_1_A();

  return 0;
}

