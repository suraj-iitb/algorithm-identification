#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
using pint = pair<ll, ll>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

ll seen[100100];
int n;
vector<vector<pint>> g(100100);
void dijkstra(int s) {
    priority_queue<pint, vector<pint>, greater<pint>> q;
    rep(i, 0, n) seen[i] = inf;
    seen[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        pint p = q.top();
        q.pop();
        int v = p.second;
        if (seen[v] < p.first) continue;

        for (int j = 0; j < g[v].size(); j++) {
            pint e = g[v][j];
            if (seen[e.second] > seen[v] + e.first) {
                seen[e.second] = seen[v] + e.first;
                q.push({seen[e.second], e.second});
            }
        }
    }
}

signed main() {
    int m, r;
    cin >> n >> m >> r;
    rep(i, 0, m) {
        ll s, t, d;
        cin >> s >> t >> d;
        g[s].push_back({d, t});
    }
    dijkstra(r);
    rep(i, 0, n) {
        if (seen[i] != inf) {
            cout << seen[i] << "\n";
        } else {
            cout << "INF\n";
        }
    }
}

