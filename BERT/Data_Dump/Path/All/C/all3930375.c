#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define all(v) v.begin(), v.end()
#define rand(l, r) std::uniform_int_distribution<>(l, r)(mt)
using lint = long long;
auto mt = std::mt19937_64(std::random_device{}());
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail){
  std::cerr << " " << head;
  debug_impl(tail...);
}
#ifndef STOPIT
#define debug(...)\
  std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
  debug_impl(__VA_ARGS__);\
  std::cerr << std::noboolalpha;
#else
#define debug 0;
#endif

template <typename T>
auto make_vector_impl(size_t sz, T t) {return std::vector<T>(sz, t);}

template <size_t N, typename T, typename U, std::enable_if_t<N == 1, std::nullptr_t> = nullptr>
auto make_vector(size_t sz, U u) {return make_vector_impl(sz, T(u));}

template <size_t N, typename T, std::enable_if_t<N == 1, std::nullptr_t> = nullptr>
auto make_vector(size_t sz) {return std::vector<T>(sz);}

template <size_t N, typename T, typename... Args, std::enable_if_t<N != 1, std::nullptr_t> = nullptr>
auto make_vector(size_t a, Args... args) {return make_vector_impl(a, make_vector<N - 1, T>(args...));}

template <typename T, typename Size_t>
auto& at(T& t, Size_t i) {return t.at(i);}

template <typename T, typename Size_t, typename... Args>
auto& at(T& t, Size_t i, Args... args) {return at(t.at(i), args...);}

// require gcc >= 7.1.0
template < class ... Keys >
class fmt_t {
    using storage_t = std::tuple< Keys ... >;
    storage_t storage;
    static constexpr std::size_t N = sizeof ... (Keys);

    // is_exact_match_impl
    template < std::size_t I, class Value >
      auto is_exact_match_impl(long, Value) const
        { return false; }

    template < std::size_t I, class Value,
      std::enable_if_t<
        std::is_same< std::decay_t< Value > , char >::value
        == std::is_same< std::tuple_element_t< I, storage_t >, char >::value,
      std::nullptr_t > = nullptr,
      class = decltype(std::declval< Value >() == std::get< I >(std::declval< storage_t >())) >
      auto is_exact_match_impl(int, Value x) const
        { return x == std::get< I >(storage); }

    template < class Value, std::size_t ... Is >
      auto find_exact_match_impl(Value x, std::integer_sequence< std::size_t, Is ... >) const {
        auto ret = false;
        (void)std::initializer_list< std::nullptr_t >
          { (ret |= is_exact_match_impl< Is >(int{}, x), nullptr) ...  };
        return ret;
      }

    template < class Value >
      auto exists_exact_match(Value x) const
      {  return find_exact_match_impl(x, std::make_index_sequence< N >()); }

    // tuple_format_impl
    template < class Tuple,  std::size_t ... Is >
    std::string tuple_format_impl(const Tuple& tuple, std::integer_sequence< std::size_t, Is ... >) const {
      std::string ret = "(";
      (void)std::initializer_list< std::nullptr_t >
        { (ret = ret + (Is == 0 ? "" : ",") + format(std::get< Is >(tuple)), nullptr) ... };
      return ret + ")";
    }

    // usual_format
    template < class Value >
    std::string usual_format(long, Value x) const
      { return std::to_string(x); }

    template < class Value, std::enable_if_t< std::is_same< std::decay_t< Value >, char >::value, std::nullptr_t > = nullptr >
    std::string usual_format(int, Value c) const
      { return std::string{'\''} + std::string{c} + std::string{'\''}; }

    std::string usual_format(int, char const* s) const
      { return "\"" + std::string(s) + "\""; }

    std::string usual_format(int, std::string const s) const
      { return "\"" + s + "\""; }

    template < class Container, class = typename Container::value_type >
    std::string usual_format(int, Container const & v) const {
      return "{" + std::accumulate(v.begin(), v .end(), std::string{},
        [this](auto const& s, auto const x) { return s + (s.empty() ? "" : ",") + this->format(x); })
        + "}";
    }

    template < class Tuple, std::size_t N = std::tuple_size< Tuple >::value >
    std::string usual_format(int, Tuple const& tuple) const
      { return tuple_format_impl(tuple, std::make_index_sequence< N >()); }

    // format
    template < class Value > std::string format(Value&& x) const
      { return exists_exact_match(x) ? std::string{'_'} : usual_format(int{}, x); }

  public:
    fmt_t()=default;
    template < Keys ... > fmt_t(Keys&& ... keys ) : storage(keys ... ){}

    template < class Value > std::string operator()(Value&& x) const
      { return format(x); }
};
template < class ... Keys > auto fmt(Keys&& ... keys)
  { return fmt_t< Keys ... >(std::forward< Keys >(keys) ... ); }

template < class Value >
auto floyd_warshall(std::vector< std::vector< Value > > adj, Value inf) {
  assert(inf <= std::numeric_limits< Value >::max());
  int n = adj.size();
  for (auto k = 0; k < n; k++) {
    for (auto i = 0; i < n; i++) {
      for (auto j = 0; j < n; j++) {
        auto & crr = adj.at(i).at(j);
        auto x = adj.at(i).at(k);
        auto y = adj.at(k).at(j);
        if (x < inf && y < inf) {
          crr = std::min(crr, x + y)  ;
        }
      }
    }
  }
  return adj;
}

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n, m; std::cin >> n >> m;
  constexpr auto inf = (1LL << 62) - 1;
  auto adj = make_vector< 2, lint >(n, n, inf);
  rep(i, 0, n) {
    at(adj, i, i) = 0;
  }
  loop(m) {
    int u, v, d; std::cin >> u >> v >> d;
    at(adj, u, v) = d;
  }
  // debug(fmt(inf)(adj));
  auto dist = floyd_warshall(adj, inf);
  // debug(fmt(inf)(dist));

  rep(i, 0, n) {
    if (at(dist, i, i) < 0) {
      std::cout << "NEGATIVE CYCLE" << std::endl;
      return 0;
    }
  }

  for (auto const & v : dist) {
    rep(i, 0, n) {
      auto x = v.at(i);
      std::cout
        << (0 < i ? " " : "")
        << (x == inf ? "INF" : std::to_string(x));
    }
    std::cout << std::endl;
  }
  return 0;
}

