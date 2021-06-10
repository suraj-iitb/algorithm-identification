#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define mp make_pair

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, int>>> edges(v, vector<pair<int, int>>(0));
    for (int i = 0; i < e; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        edges[s].emplace_back(mp(d, t));
    }
    vector<int> dist(v, 1001001001);
    vector<bool> seen(v);
    seen[r] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[r] = 0;
    pq.push(mp(0, r));
    while (!pq.empty()) {
        auto x = pq.top();
        seen[x.second] = true;
        pq.pop();
        for (auto nv : edges[x.second]) {
            if (seen[nv.second]) continue;
            if (dist[x.second] + nv.first < dist[nv.second]) {
                dist[nv.second] = dist[x.second] + nv.first;
                pq.push(mp(dist[nv.second], nv.second));
            }
        }
    }
    for (int i = 0; i < v; ++i) {
        if (dist[i] == 1001001001) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

