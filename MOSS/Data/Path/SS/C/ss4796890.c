#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

struct edge { int to, cost; };  // 辺
const int MAXV = 100100;            // 頂点 V の最大値
int V;                          // 頂点 V の数
vector<edge> g[MAXV];           // graph
int d[MAXV];                 // 始点からの最短距離を表す配列

void dijkstra(int s) {
    fill(d, d + V, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({0, s});

    while (!que.empty()) {
        pair<int, int> p = que.top();
        que.pop();

        int v = p.second;

        // 現状の始点 s から 頂点 v までの距離 d[v] が次に出てくる頂点 v までの最短経路がすでに小さいなら見る必要がない
        if (d[v] < p.first) continue;

        for (edge e : g[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push({d[e.to], e.to});
            }
        }
    }
}

int main() {
    int E, r;
    cin >> V >> E >> r;
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].emplace_back((edge){t, d});
    }
    dijkstra(r);
    rep(i, V) {
        if (d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}

