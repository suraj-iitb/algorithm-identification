#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;
using ll = long long;

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, int>>> G(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(make_pair(t, d));
    }
    priority_queue<int> que;
    que.push(r);
    vector<bool> seen(v);
    vector<int> dist(v, 1e9);
    dist[r] = 0;
    seen[r] = true;
    while (!que.empty()) {
        int now = que.top();
        que.pop();
        for (auto p : G[now]) {
            int next = p.first;
            int d = dist[now] + p.second;
            if (dist[next] > d) {
                que.push(next);
                dist[next] = d;
            }
        }
    }
    for (auto d : dist) {
        if (d == 1e9) cout << "INF" << endl;
        else cout << d << endl;
    }
}
