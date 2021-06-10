#include <limits>
#include <iostream>
#include <type_traits>
#include <vector>
#include <cstdint>
#include <queue>
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"
constexpr unsigned int mod                  = 1000000007;
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};

using i32   = int32_t;
using i64   = int64_t;
using u32   = uint32_t;
using u64   = uint64_t;
using uint  = unsigned int;
using usize = std::size_t;
using ll    = long long;
using ull   = unsigned long long;
using ld    = long double;
template<typename T, usize n>
using arr = T (&)[n];
template<typename T, usize n>
using c_arr = const T (&)[n];
template<typename T>
T in()
{
    T v;
    return std::cin >> v, v;
}
template<typename T, typename Uint, usize n, usize i>
T in_v(typename std::enable_if<(i == n), c_arr<Uint, n>>::type) { return in<T>(); }
template<typename T, typename Uint, usize n, usize i>
auto in_v(typename std::enable_if<(i < n), c_arr<Uint, n>>::type& szs)
{
    const usize s = (usize)szs[i];
    std::vector<decltype(in_v<T, Uint, n, i + 1>(szs))> ans(s);
    for (usize j = 0; j < s; j++) { ans[j] = in_v<T, Uint, n, i + 1>(szs); }
    return ans;
}
template<typename T, typename Uint, usize n>
auto in_v(c_arr<Uint, n> szs) { return in_v<T, Uint, n, 0>(szs); }
template<typename... Types>
auto in_t() { return std::tuple<std::decay_t<Types>...>{in<Types>()...}; }

template<typename T>
void out(const T& v) { std::cout << v; }
template<typename T>
void out(const std::vector<T>& v)
{
    for (usize i = 0; i < v.size(); i++) {
        if (i > 0) { std::cout << ' '; }
        out(v[i]);
    }
    std::cout << "\n";
}
template<typename T1, typename T2>
void out(const std::pair<T1, T2>& v) { out(v.first), std::cout << ' ', out(v.second); }
template<typename T, typename... Args>
void out(const T& v, const Args... args) { out(v), std::cout << ' ', out(args...); }
template<typename... Args>
void outln(const Args... args) { out(args...), std::cout << '\n'; }
template<typename... Args>
void outel(const Args... args) { out(args...), std::cout << std::endl; }


template<typename Cost = usize>
struct edge
{
    using cost_type = Cost;
    usize u, v;
    Cost c;
    edge(const usize u, const usize v) : u{u}, v{v}, c{1} {}
    edge(const usize u, const usize v, const Cost& c) : u{u}, v{v}, c{c} {}
    operator usize() { return v; }
    usize from() const { return u; }
    usize to() const { return v; }
    Cost cost() const { return c; }
    friend std::ostream& operator<<(std::ostream& os, const edge& e) { return os << e.u << "->" << e.v << ":" << e.c; }
};
template<typename Edge>
class base_graph
{
public:
    base_graph(const usize n) : v{n}, es(n), res(n) {}
    void add_edge(const usize u, const usize v, const bool bi = false)
    {
        es[u].emplace_back(u, v);
        if (bi) { es[v].emplace_back(v, u); }
    }
    template<typename Cost>
    void add_edge(const usize u, const usize v, const Cost& c, const bool bi = false)
    {
        es[u].emplace_back(u, v, c);
        if (bi) { es[v].emplace_back(v, u, c); }
    }
    std::vector<Edge>& operator[](const usize u) { return es[u]; }
    const std::vector<Edge>& operator[](const usize u) const { return es[u]; }
    std::vector<Edge>& from(const usize u) { return es[u]; }
    const std::vector<Edge>& from(const usize u) const { return es[u]; }
    std::vector<Edge>& to(const usize v) { return res[v]; }
    const std::vector<Edge>& to(const usize v) const { return res[v]; }
    usize size() const { return v; }

private:
    usize v;
    std::vector<std::vector<Edge>> es, res;
};
template<typename Edge>
using base_tree = base_graph<Edge>;
using graph     = base_graph<edge<>>;
using tree      = base_graph<edge<>>;
template<typename Cost>
using cost_graph = base_graph<edge<Cost>>;
template<typename Cost>
using cost_tree = base_graph<edge<Cost>>;
template<typename Edge>
std::vector<typename Edge::cost_type> dijkstra(const base_graph<Edge>& g, const usize s)
{
    using Cost = typename Edge::cost_type;
    std::vector<Cost> d(g.size(), inf_v<Cost>);
    using P = std::pair<Cost, usize>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
    d[s] = 0, q.push({0, s});
    while (not q.empty()) {
        const Cost cost = q.top().first;
        const usize v   = q.top().second;
        q.pop();
        if (d[v] < cost) { continue; }
        for (const auto& e : g[v]) {
            const auto cost = e.cost();
            const usize to  = e.to();
            if (d[to] <= d[v] + cost) { continue; }
            d[to] = d[v] + cost, q.push({d[to], to});
        }
    }
    return d;
}
int main()
{
    const auto V = in<usize>();
    const auto E = in<usize>();
    const auto r = in<usize>();
    cost_graph<ll> g(V);
    for (usize i = 0; i < E; i++) {
        const usize s = in<usize>();
        const usize t = in<usize>();
        const usize d = in<ll>();
        g.add_edge(s, t, d);
    }
    const auto ds = dijkstra(g, r);
    for (usize i = 0; i < V; i++) {
        if (ds[i] >= inf_v<ll>) {
            outln("INF");
        } else {
            outln(ds[i]);
        }
    }
    return 0;
}

