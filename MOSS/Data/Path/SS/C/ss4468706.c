#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

const int INF = 2E+9;

struct edge {
    int t;
    int d;
};
bool operator<(const edge &e1, const edge &e2) {
    return e1.d < e2.d;
}
bool operator>(const edge &e1, const edge &e2) {
    return e1.d > e2.d;
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<edge>> G(V);
    int si, ti, di;
    rep(i, E) {
        cin >> si >> ti >> di;
        G[si].push_back({ti, di});
    }

    int dist[V];
    fill(dist, dist+V, INF);
    dist[r] = 0;

    bool used[V];
    fill(used, used+V, false);
    used[r] = true;

    priority_queue<edge, vector<edge>, greater<edge>> que;
    for (auto e: G[r]) que.push({e.t, e.d});

    while (!que.empty()) {
        edge e = que.top();
        que.pop();

        if (!used[e.t]) {
            dist[e.t] = e.d;
            used[e.t] = true;
            for (auto ne: G[e.t]) {
                if (dist[ne.t] > dist[e.t] + ne.d) {
                    dist[ne.t] = dist[e.t] + ne.d;
                    que.push({ne.t, dist[e.t] + ne.d});
                }
            }
        }
    }

    rep(i, V) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}
