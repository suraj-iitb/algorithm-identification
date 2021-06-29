#line 1 "GRL_1_A_abstract.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"

#include <bits/stdc++.h>  // clang-format off
using Int = long long;
#define REP_(i, a_, b_, a, b, ...) for (Int i = (a), lim##i = (b); i < lim##i; i++)
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define ALL(v) std::begin(v), std::end(v)
struct SetupIO { SetupIO() { std::cin.tie(nullptr), std::ios::sync_with_stdio(false), std::cout << std::fixed << std::setprecision(13); } } setup_io;
#ifndef dump
#define dump(...)
#endif  // clang-format on

/**
 *    author:  knshnb
 *    created: Sun Aug 16 15:46:30 JST 2020
 **/

#define CALL_FROM_TEST
#line 1 "/Users/knshnb/competitive_programming/competitive_library/src/Graph/AbstractDijkstra.hpp"
template <class Dist, class Key, class Delta>  // Delta: Key, (Key, Dist -> void) -> void
std::map<Key, Dist> dijkstra(Key s, Delta delta) {
    std::map<Key, Dist> dist;
    using P = std::pair<Dist, Key>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
    q.push({dist[s] = Dist(), s});
    while (!q.empty()) {
        std::pair<Dist, Key> p = q.top();
        q.pop();
        if (dist[p.second] < p.first) continue;
        delta(p.second, [&](Key to, Dist d) -> void {
            if (dist.count(to) && dist[to] <= p.first + d) return;
            q.push({dist[to] = p.first + d, to});
        });
    }
    return dist;
}
#line 20 "GRL_1_A_abstract.test.cpp"
#undef CALL_FROM_TEST

signed main() {
    Int n, m, r;
    std::cin >> n >> m >> r;
    struct Edge {
        Int to, cost;
    };
    std::vector<std::vector<Edge>> g(n);
    REP(i, m) {
        Int s, t, d;
        std::cin >> s >> t >> d;
        g[s].push_back({t, d});
    }
    auto delta = [&](Int from, auto update) -> void {
        for (Edge& edge : g[from]) {
            update(edge.to, edge.cost);
        }
    };
    auto dist = dijkstra<Int>(r, delta);
    REP(i, n) {
        if (dist.count(i)) {
            std::cout << dist[i] << "\n";
        } else {
            std::cout << "INF\n";
        }
    }
}

