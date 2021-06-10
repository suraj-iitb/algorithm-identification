#include <bits/stdc++.h>
using namespace std;
using Item = pair<int, int>;

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<set<pair<int, int>>> G(n);
    while (m--) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].emplace(t, d);
    }

    priority_queue<Item, vector<Item>, greater<Item>> pq;
    vector<int> dist(n, INT_MAX);
    pq.emplace(0, r);
    dist[r] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : G[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(w, v);
            }
        }
    }

    for (auto d : dist) {
        if (d == INT_MAX)
            cout << "INF" << endl;
        else
            cout << d << endl;
    }
}
