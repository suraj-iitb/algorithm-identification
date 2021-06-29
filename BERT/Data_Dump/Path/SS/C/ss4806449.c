#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll N, M, r;

vector<ll> dijkstra(int start, vector<vector<vector<ll>>> &Graph) {
    vector<ll> dist(N, 10e13);  // 0始まり
    priority_queue<P, vector<P>, greater<P>> pq;

    dist.at(start) = 0;
    pq.emplace(dist.at(start), start);  //最初の要素をキューに追加

    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int cur = p.second;
        if (dist.at(cur) < p.first) continue;
        for (auto &x : Graph.at(cur)) {
            if (dist.at(x[0]) > dist.at(cur) + x[1]) {
                dist.at(x[0]) = dist.at(cur) + x[1];
                pq.emplace(dist.at(x[0]), x[0]);  //要素をキューに追加
            }
        }
    }
    return dist;
}

int main() {
    cin >> N >> M >> r;

    vector<vector<vector<ll>>> Graph(N);  // 0始まり
    for (int i = 0; i < M; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        Graph[a].push_back({b, c});
    }
    vector<ll> ans = dijkstra(r, Graph);
    rep(i, N) {
        if (ans[i] > 10e12)
            cout << "INF" << endl;
        else
            cout << ans[i] << endl;
    }
}

