#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// pair -> cost, to
using P = pair<int, int>;

vector<int> dijkstra(const int start,const int N,const vector<P>* G) {
    vector<int> dist(N, INF);
    vector<bool> used(N, false);
    dist[start] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0,start));
    while(!que.empty()) {
        int d, v;
        tie(d, v) = que.top();
        que.pop();
        if (used[v]) continue;
        used[v] = true;
        dist[v] = d;
        for (const P& e: G[v]) {
            if (dist[e.second] <= d + e.first) continue;
            que.push(P(d + e.first, e.second));
        }
    }
    return dist;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int V, E, start;
    cin >> V >> E >> start;
    vector<P> G[V];
    for (int i = 0; i < E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        G[from].push_back(P(cost, to));
    }
    auto d = dijkstra(start, V, G);
    for (int i = 0; i < d.size(); i++) {
        if (d[i] >= INF)  cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}
