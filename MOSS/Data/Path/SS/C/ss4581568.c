#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, cost;
};

vector<int> dijkstra(const vector<vector<edge>>& g, int s) {

    int n = g.size();
    const int INF = numeric_limits<int>::max();
    vector<int> dist(n, INF);

    using P = pair<int,int>;
    priority_queue<P, vector<P>, greater<P>> que;

    que.emplace(0, s);
    dist[s] = 0;
    while (!que.empty()) {
        int d, v; tie(d, v) = que.top(); que.pop();
        if (dist[v] < d) continue;
        for (const edge& e : g[v]) {
            int nxt = d + e.cost;
            if (dist[e.to] > nxt) {
                dist[e.to] = nxt;
                que.emplace(nxt, e.to);
            }
        }
    }
    return dist;
}

int main() {

    int n, m, s; cin >> n >> m >> s;
    vector<vector<edge>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back((edge){v, c});
    }

    const int INF = numeric_limits<int>::max();
    for (int d : dijkstra(g, s)) {
        if (d < INF) cout << d << endl;
        else cout << "INF" << endl;
    }

    return 0;
}

