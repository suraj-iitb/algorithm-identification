#include <bits/stdc++.h>
using namespace std;

class Dijkstra {
    int n;
    vector<vector<pair<int, double>>> adj;
    vector<double> d;

public:
    Dijkstra(int n) : n(n), adj(n), d(n, numeric_limits<double>::infinity()) {}

    void add_edge(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    void add_arc(int a, int b, double w) {
        assert(0 <= a && a < n && 0 <= b && b < n);
        adj[a].emplace_back(b, w);
    }

    void run(int a) {
        d[a] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
        que.emplace(0, a);

        while (que.size()) {
            auto top = que.top();
            que.pop();
            int u = top.second;

            for (auto& p : adj[u]) {
                int v = p.first;
                double w = p.second;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    que.emplace(d[v], v);
                }
            }
        }
    }

    double dist(int a) {
        return d[a];
    }
};

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    Dijkstra g(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g.add_arc(a, b, w);
    }
    g.run(r);
    for (int i = 0; i < n; i++) {
        double d = g.dist(i);
        if (d == numeric_limits<double>::infinity()) cout << "INF" << '\n';
        else cout << (long long) d << '\n';
    }
}
