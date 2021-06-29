
#include <bits/stdc++.h>

using namespace std;
using p_int = pair<int, int>;
struct edge { int to, cost; };

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int INF = (int) 1e9 + 1;
    int V, E, r;
    cin >> V >> E >> r;
    vector<edge> g[V];
    int s, t;
    for (int i = 0; i < E; ++i) {
        edge e{};
        cin >> s >> e.to >> e.cost;
        g[s].push_back(e);
    }

    priority_queue<p_int, vector<p_int>, greater<>> que;
    int d[V];
    fill(d, d + V, INF);
    d[r] = 0;
    que.push(p_int(0, r));

    while (!que.empty()) {
        p_int p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i = 0; i < g[v].size(); ++i) {
            edge e = g[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(p_int(d[e.to], e.to));
            }
        }
    }

    for (auto e: d) {
        if (e < INF) {
            cout << e << '\n';
        } else {
            cout << "INF" << '\n';
        }
    }

    return 0;
}

