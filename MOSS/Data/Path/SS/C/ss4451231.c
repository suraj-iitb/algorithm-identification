#include <limits>
#include <queue>
#include <vector>

template<typename T, typename I, typename J, typename F, typename G, typename Z, typename INF>
std::vector<T> dijkstra(I begin_cnct, I end_cnct, J begin_cost, int s, F &&f, G &&g, Z &&zero, INF &&inf) {
    int n = end_cnct - begin_cnct;
    std::vector<T> ret(n, inf());
    using P = std::pair<T, int>;
    auto c = [&](P a, P b) -> bool { return g(a.first, b.first); };
    std::priority_queue<P, std::vector<P>, decltype(c)> pq(c);
    ret[s] = zero();
    pq.push({ret[s], s});
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (g(p.first, ret[v])) { continue; }
        for (int i = 0; i < (begin_cnct + v)->size(); i++) {
            int u = (*(begin_cnct + v))[i];
            T dist_u = f(ret[v], (*(begin_cost + v))[i]);
            if (g(ret[u], dist_u)) { ret[u] = dist_u, pq.push({dist_u, u}); }
        }
    }
    return ret;
}

template<typename T, typename I, typename J>
std::vector<T> basic_dijkstra(I begin_cnct, I end_cnct, J begin_cost, int s) {
    auto zero = []() -> T { return 0; };
    auto inf = []() -> T { return std::numeric_limits<T>::max(); };
    auto f = [&](T a, T b) -> T { return a == inf() ? inf() : a + b; };
    auto g = [](T a, T b) -> bool { return a > b; };
    return dijkstra<T>(begin_cnct, end_cnct, begin_cost, s, f, g, zero, inf);
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<int> cnct[110000], cost[110000];
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        cnct[s].push_back(t), cost[s].push_back(d);
    }
    vector<int> dist = basic_dijkstra<int>(cnct, cnct + V, cost, r);
    for (int i = 0; i < V; i++) { cout << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl; }
}
