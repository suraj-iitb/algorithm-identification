#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL << 60;

using Graph = vector<vector<pair<int, long long>>>;

vector<long long> dijkstra(const Graph& G, int N, int s) {
    vector<long long> dist(N, INF);
    priority_queue<pair<long long, int>> pq;
    dist[s] = 0;
    pq.emplace(-dist[s], s);
    while (!pq.empty()) {
        int v = pq.top().second; pq.pop();
        for (auto p : G[v]) {
            if (chmin(dist[p.first], dist[v] + p.second)) pq.emplace(-dist[p.first], p.first);
        }
    }
    return dist;
}


int main() {
    int N, M, r; cin >> N >> M >> r;
    Graph G(N);
    rep(i, M) {
        int s, t, d; cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }
    vector<long long> dist = dijkstra(G, N, r);
    for (auto ans : dist) {
        if (ans == INF) cout << "INF" << endl;
        else cout << ans << endl;
    }
}

