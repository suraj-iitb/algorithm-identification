#include <bits/stdc++.h>
using namespace std;

bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }

    return false;
}

struct edge {
    int to, cost;
};

vector<vector<edge>> graph;

int main(void) {
    int v, e, r;
    cin >> v >> e >> r;

    graph.resize(v);

    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;

        graph[s].push_back(edge{t, d}); 
    }

    const int inf = 1 << 30;

    vector<int> dist(v, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

    dist[r] = 0;
    que.push(make_pair(0, r));

    while (!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();

        int cost = p.first;
        int from = p.second;

        if (dist[from] < cost) continue;
        for (const auto& e : graph[from]) {
            if (chmin(dist[e.to], dist[from] + e.cost)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    for (int i = 0; i < v; i++) {
        cout << (dist[i] == inf ? "INF" : to_string(dist[i])) << endl;
    }

    return 0;
}
