#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

struct edge {
    int to;
    int cost;
};
using P = pair<ll, ll>;
vector<vector<edge>> G;
vector<ll> d;
void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d.begin(), d.end(), 1e18);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        rep(i, G[v].size()) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    G.resize(V);
    d.resize(V);

    rep(i, E) {
        int x, y, d;
        cin >> x >> y >> d;

        G[x].push_back({y, d});
    }

    dijkstra(r);

    rep(i, V) {
        if (d[i] == 1e18)
            cout << "INF";
        else
            cout << d[i];
        cout << "\n";
    }

    return 0;
}
