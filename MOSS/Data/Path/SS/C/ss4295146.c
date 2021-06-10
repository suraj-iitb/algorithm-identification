#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int V, E, r, s, t, d;
    cin >> V >> E >> r;
    vector<vector<pair<int, int>>> edge(V);
    rep(i, E) {
        cin >> s >> t >> d;
        edge[s].push_back(make_pair(t, d));
    }
    vector<ll> dist(V, 1e18);
    priority_queue<pair<ll, int>> q;
    q.push(make_pair(0, r));
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (-p.first >= dist[p.second]) continue;
        dist[p.second] = -p.first;
        rep(i, edge[p.second].size()) {
            q.push(make_pair(-dist[p.second] - edge[p.second][i].second, edge[p.second][i].first));
        }
    }
    rep(i, V) {
        if (dist[i] == 1e18) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}
