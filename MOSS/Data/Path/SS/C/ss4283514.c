#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<lint, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const lint INF = 1LL << 60;

struct Edge {
    int to, cost;
};

vector<vector<Edge>> g;
vec dist;

void dijkstra(int r) {
    fill(all(dist), INF);
    dist[r] = 0;

    priority_queue<pint, vector<pint>, greater<pint>> que;
    que.push(pint(0, r));

    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.second;

        if (dist[v] < p.first) continue;

        for (auto&& e : g[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.push(pint(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    g.resize(v);
    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back((Edge){t, d});
    }

    dist.resize(v);
    dijkstra(r);

    rep(i, v) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}
