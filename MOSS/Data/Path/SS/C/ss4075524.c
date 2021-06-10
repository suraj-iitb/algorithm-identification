#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

vector<pair<int, int>> g[maxn];
int dist[maxn], parent[maxn], n, m, src;


void dijkstra(int src) {
    memset(dist, 63, sizeof dist);
    int inf = dist[0];
    dist[src] = 0;
    set<pair<int, int>> q;

//    dist , node
    q.insert({0, src});
    while (!q.empty()) {
        int len = q.begin()->first;
        int node = q.begin()->second;

        q.erase({len, node});
        for (auto x: g[node]) {
            if (dist[x.first] > dist[node] + x.second) {
                q.erase({dist[x.first], x.first});
                parent[x.first] = node;
                dist[x.first] = x.second + dist[node];
                q.insert({dist[x.first], x.first});
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (dist[i] == inf)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
}

void solve() {
    cin >> n >> m >> src;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({b, c});
    }
    dijkstra(src);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;

    while (t--)
        solve();
    return 0;
}
