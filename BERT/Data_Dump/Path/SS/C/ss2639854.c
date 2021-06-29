#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>

using namespace std;


struct edge {
    int src;
    int dst;
    int weight;

    edge(int src, int dst, int w) : src(src), dst(dst), weight(w) {}
};

bool operator < (const edge &a, const edge &b) {
  return a.weight > b.weight;
}


int main() {
    int v, e, r;
    cin >> v >> e >> r;

    vector<vector<edge>> G(v);
    for (int i = 0; i < e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(s, t, d);
    }

    // Dijkstra's algorithm (with pritority queue)
    auto INF = numeric_limits<int>::max();
    vector<int> d(v, INF);
    vector<bool> visited(v, false);
    priority_queue<edge> Q;

    Q.emplace(-1, r, 0);
    d[r] = 0;
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();
        visited[e.dst] = true;
        if (d[e.dst] < e.weight)
            continue;

        for (auto& x : G[e.dst]) {
            if (visited[x.dst])
                continue;
            int w = x.weight + d[e.dst];
            if (w < d[x.dst]) {
                d[x.dst] = w;
                Q.emplace(e.dst, x.dst, w);
            }
        }
    }

    for (int i = 0; i < v; ++i) {
        if (d[i] != INF) {
            cout << d[i] << endl;
        } else {
            cout << "INF" << endl;
        }
    }

    return 0;
}
