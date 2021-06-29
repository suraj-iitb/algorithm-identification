#include <bits/stdc++.h>
using namespace std;
struct Edge { int to; long long cost; };

template<class T>
vector<T> Dijkstra(const vector<vector<Edge>> &G, int s, T def) {
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<T> dist((int)G.size(), def);
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()) {
        int cur = pq.top().second; pq.pop();
        for(auto &e : G[cur]) {
            if(dist[e.to] > dist[cur] + e.cost) {
                dist[e.to] = dist[cur] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

void solve() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<Edge>> G(V);
    for(int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    const long long INF = 1e18;
    for(auto &d : Dijkstra(G, r, INF)) {
        if(d == INF) cout << "INF" << '\n';
        else cout << d << '\n';
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

