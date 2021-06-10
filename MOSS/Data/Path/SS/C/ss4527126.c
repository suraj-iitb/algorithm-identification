#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7

using P = pair<int, int>;
struct Graph {
    int to;
    int cost;
    Graph(int a, int b) {
        to = a;
        cost = b;
    }
};

int main() {
    // input
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<Graph>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(Graph(t, d));
        // G[t].push_back(Graph(s, d));
    }

    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> dist(V, INF);

    // main
    que.push(P(0, r));
    dist[r] = 0;
    while (!que.empty()) {
        P edge = que.top();
        que.pop();

        if (dist[edge.second] < edge.first) {
            continue;
        }
        
        for (auto g : G[edge.second]) {
            if (dist[edge.second] + g.cost < dist[g.to]) {
                dist[g.to] = dist[edge.second] + g.cost;
                que.push(P(dist[g.to], g.to));
            }
        }
    }

    // output
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF) {
            cout << "INF" <<endl;
        }
        else {
            cout << dist[i] <<endl;
        }
    }
    return 0;
}

