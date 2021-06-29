#define DEBUG 0
#include <bits/stdc++.h>
#define loop(n) for (lint ngtkana_is_a_genius = 0; ngtkana_is_a_genius < lint(n); ngtkana_is_a_genius++)
#define rep(i, begin, end) for (lint i = lint(begin); (i) < lint(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto&& a, auto b){ if (a > b) {a = b; return true;} return false; };
auto cmx = [](auto&& a, auto b){ if (a < b) {a = b; return true;} return false; };
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { std::cerr << " " << head; debug_impl(tail...); }
#if DEBUG
#define debug(...)\
  do {\
    std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_impl(__VA_ARGS__);\
    std::cerr << std::noboolalpha;\
  } while (false)
#else
#define debug(...) {}
#endif

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr>
std::istream& operator>> (std::istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, std::enable_if_t<!std::is_same< Container, std::string >::value, std::nullptr_t> = nullptr >
std::ostream& operator<< (std::ostream& os, Container const& v) {
 os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& tuple_input_impl(std::istream& os, Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { (void)std::initializer_list<int>{((void)(os >> std::get< Inds >(tuple)), 0)...}; return os; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::istream& operator>> (std::istream& os, Tuple<Args...>& tuple)
  { return tuple_input_impl(os, tuple, std::index_sequence_for<Args...>()); }

template < template < typename ... > class Tuple,  typename... Args, std::size_t ... Inds, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& tuple_output_impl(std::ostream& os, const Tuple<Args...>& tuple, std::integer_sequence<std::size_t, Inds...>)
  { os << "("; (void)std::initializer_list<int>{((void)(os << (Inds > 0 ? "," : "") << std::get< Inds >(tuple)), 0)...}; return os << ")"; }
template < template < typename ... > class Tuple,  typename... Args, std::size_t = std::tuple_size< Tuple < Args ... > >::value >
std::ostream& operator<< (std::ostream& os, const Tuple<Args...>& tuple)
 { return tuple_output_impl(os, tuple, std::index_sequence_for<Args...>()); }

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n, m, r;
  std::cin >> n >> m >> r;
  std::vector<std::vector<std::pair<int,int>>> graph(n);
  loop(m) {
    int u, v, d;
    std::cin >> u >> v >> d;
    graph.at(u).emplace_back(v, d);
  }
  debug(graph);

  int inf = std::numeric_limits<int>::max();
  std::vector<int> dist(n, inf);
  using node = std::pair<int,int>;
  std::priority_queue<node,std::vector<node>,std::greater<>> que;
  que.emplace(0, r);
  while (!que.empty()) {
    int x, dx; std::tie(dx, x) = que.top(); que.pop();
    if (dist.at(x) < dx) continue;
    dist.at(x) = dx;
    for (auto&& e : graph.at(x)) {
      int y, w; std::tie(y, w) = e;
      int dy = dx + w;
      if (dist.at(y) <= dy) continue;
      dist.at(y) = dy;
      que.emplace(dy, y);
    }
  }
  debug(dist);

  for (int x : dist) {
    std::cout << (x==inf ? "INF" : std::to_string(x)) << std::endl;
  }
  return 0;
}
