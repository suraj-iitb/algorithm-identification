#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
struct Edge {
    int to;
    long long cost;
};

using Graph = vector<vector<Edge>>;
using Pli = pair<long long, int>;

vector<long long> dijkstra(const Graph &G, int s) {
    int N = G.size();
    vector<long long> dist(N, 1LL << 60);
    priority_queue<Pli, vector<Pli>, greater<Pli>> q;
    dist[s] = 0;
    q.emplace(dist[s], s);
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto &e : G[v]) {
            if (dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            q.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    Graph g = Graph(V, vector<Edge>());
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].emplace_back(Edge{t, d});
    }

    auto res = dijkstra(g, r);

    for (auto x : res) {
        cout << (x == (1LL << 60) ? "INF" : to_string(x)) << endl;
    }
}
