#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const long long INF = 1LL << 60;    // 1.15x10^18
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using edge = pair<int, long long>;
using Graph = vector<vector<edge>>;

vector<long long> dijkstra(const Graph &g, int s) {
    vector<long long> dist(g.size(), INF);
    using Pi = pair<long long, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> que;
    dist[s] = 0; que.emplace(dist[s], s);
    while (!que.empty()) {
        long long cost; int u; tie(cost, u) = que.top(); que.pop();
        if (dist[u] < cost) continue;
        for (auto &e: g[u]) {
            int v; long long nc; tie(v, nc) = e;
            if (chmin(dist[v], dist[u] + nc)) que.emplace(dist[v], v);
        }
    }
    return dist;
}

int main() {
    int n, m, r; cin >> n >> m >> r;
    Graph g(n);
    while (m--) {
        int s, t, d; cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    for (auto dist: dijkstra(g, r)) {
        if (dist == INF) cout << "INF" << endl;
        else cout << dist << endl;
    }
    return 0;
}
