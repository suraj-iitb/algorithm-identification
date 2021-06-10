#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

struct edge
{
    int to; ll cost;
    edge(int to, ll cost) : to(to), cost(cost) {}
};

vector<ll> dijkstra(const vector<vector<edge>> &g, int s)
{
    using P = pair<ll, int>;

    priority_queue<P, vector<P>, greater<P>> q;
    vector<ll> dist(g.size(), linf);

    dist[s] = 0; q.emplace(0, s);
    while (!q.empty()) {
        ll d; int now;
        tie(d, now) = q.top(); q.pop();
        if (dist[now] < d) continue;
        for (auto &e: g[now]) {
            if (dist[e.to] > d + e.cost) {
                dist[e.to] = d + e.cost;
                q.emplace(dist[e.to], e.to);
            }
        }
    }
    return move(dist);
}

int main()
{
    int v, e, r; cin >> v >> e >> r;

    vector<vector<edge>> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, d; cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }

    auto dist = dijkstra(g, r);

    for (int i = 0; i < v; i++) {
        if (dist[i] >= linf) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}

