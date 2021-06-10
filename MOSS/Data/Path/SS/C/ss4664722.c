#include <vector>

template<typename T>
struct edge {
    int to; T cost;
    edge (int to, T cost = 1) : to(to), cost(cost) { }
    bool operator< (const edge &r) const { return (cost < r.cost); }
};

template<typename T>
using graph = std::vector<std::vector<edge<T>>>;

#include <vector>
#include <queue>
#include <functional>
#include <tuple>

template <typename T>
std::vector<T> dijkstra(const graph<T> &g, int s){
    using P = std::pair<T, int>;
    std::vector<T> ret(g.size(), -1);
    std::priority_queue<P, std::vector<P>, std::greater<P>> que;
    que.emplace(ret[s], s); ret[s] = 0;
    while (not que.empty()) {
        int v; T c;
        std::tie(c, v) = que.top();
        que.pop();
        if (ret[v] < c) continue;
        for (const auto &e : g[v]) {
            if (ret[e.to] > ret[v] + e.cost or ret[e.to] == -1) {
                ret[e.to] = ret[v] + e.cost;
                que.emplace(ret[e.to], e.to);
            }
        }
    }
    return ret;
}

#include <iostream>

int main() {
    int n, m, r;
    std::cin >> n >> m >> r;

    graph<long long> g(n);
    for (int i = 0; i < m; i++) {
        int src, dst;
        long long cst;
        std::cin >> src >> dst >> cst;
        g[src].emplace_back(dst, cst);
    }

    for (long long cst : dijkstra(g, r)) {
        if (cst == -1) std::cout << "INF" << '\n';
        else std::cout << cst << '\n';
    }

    return 0;
}
