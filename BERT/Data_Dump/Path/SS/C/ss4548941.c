#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to;
    int cost;
};

struct vert {
    vector<edge> edges;
};

void dijkstra(
        const vector<vert>& verts,
        int initPoint,
        vector<long long>& dist,
        vector<long long>& prev
        ) {
    typedef pair<long long, int> P;
    priority_queue<P, vector<P>, greater<>> q;
    vector<bool> done(verts.size(), false);
    q.push(P(0, initPoint));
    dist[initPoint] = 0;
    prev[initPoint] = initPoint;
    while (!q.empty()) {
        auto info = q.top(); q.pop();
        int current = info.second;

        if (done[current]) continue;
        done[current] = true;
        for (const auto& e: verts[current].edges) {
            if (done[e.to]) continue;
            if (dist[e.to] > dist[current] + e.cost) {
                dist[e.to] = dist[current] + e.cost;
                prev[e.to] = current;
                q.push(P(dist[e.to], e.to));
            }
        }
    }
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<long long> dist(V, 1000000000);
    vector<long long> prev(V, -1);
    vector<vert> verts(V);
    for (int i = 0; i < E; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        verts[from].edges.push_back(edge{from: from, to: to, cost: cost});
    }
    dijkstra(verts, r, dist, prev);
    for (int i = 0; i < V; ++i) {
        if (prev[i] == -1) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}

