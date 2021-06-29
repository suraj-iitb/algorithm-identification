#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()
template<class T>bool chmax(T& a, const T& b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T& a, const T& b) { if (b<a) { a=b; return 1;} return 0;}

const ll INF = 1LL << 60;
struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};
using Graph = vector<vector<Edge>>;

int main() {
    int V, E, s; cin >> V >> E >> s;
    Graph G(V);
    rep(i, E) {
        int a, b, w; cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
    vector<ll> dist(V, INF);
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
    que.push({0, s});

    while (!que.empty()) {
        int d = que.top().first;
        int v = que.top().second;
        que.pop();
        if (d > dist[v]) continue;

        for (auto e : G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push({dist[e.to], e.to});
            }
        }
    }
    for (int v = 0; v < V; ++v) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
}
