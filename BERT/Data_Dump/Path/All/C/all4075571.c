#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define MOD 1000000007
#define maxn 100010

vector<int> g[maxn];
int dist[maxn], parent[maxn], n, m, src;
//
//
//void dijkstra(int src) {
//    memset(dist, 63, sizeof dist);
//    int inf = dist[0];
//    dist[src] = 0;
//    set<pair<int, int>> q;
//
////    dist , node
//    q.insert({0, src});
//    while (!q.empty()) {
//        int len = q.begin()->first;
//        int node = q.begin()->second;
//
//        q.erase({len, node});
//        for (auto x: g[node]) {
//            if (dist[x.first] > dist[node] + x.second) {
//                q.erase({dist[x.first], x.first});
//                parent[x.first] = node;
//                dist[x.first] = x.second + dist[node];
//                q.insert({dist[x.first], x.first});
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//        if (dist[i] == inf)
//            cout << "INF" << endl;
//        else
//            cout << dist[i] << endl;
//}

vector<pair<pair<int, int>, int>> ed;

void bellman(int src) {
    memset(dist, 63, sizeof dist);
    int inf = dist[0];

    dist[src] = 0;
    int xx;
    for (int i = 0; i < n; i++) {
        xx = -1;
        for (auto x: ed) {
            if (dist[x.first.first] < inf and dist[x.first.first] + x.second < dist[x.first.second]) {
                dist[x.first.second] = x.second + dist[x.first.first];
                xx = 2;
            }
        }
    }
    if (xx == -1) {
        for (int i = 0; i < n; i++)
            if (dist[i] == inf)
                cout << "INF" << endl;
            else
                cout << dist[i] << endl;
    } else
        cout << "NEGATIVE CYCLE" << endl;
}

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

int sz[maxn], p[maxn];

void init(int n) {
    for (int i = 0; i <= n; i++)
        p[i] = i, sz[i] = 1;
}

int find(int n) {
    return (n == p[n]) ? n : p[n] = find(p[n]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return false;
    if (sz[b] > sz[a])
        swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    return true;
}

void mst() {
    sort(ed.begin(), ed.end(), comp);
    int ans = 0;
    for (auto x:ed) {
        if (unite(x.first.first, x.first.second))
            ans += x.second;
    }
    cout << ans << endl;
}

int color[maxn];

bool dfs(int u) {
    color[u] = 1;
    for (auto x: g[u]) {
        if (color[x] == 0) {
            if (dfs(x))
                return true;
        } else if (color[x] == 1)
            return true;
    }
    color[u] = 2;
    return false;
}

int mat[110][110];

void solve() {
    cin >> n >> m;

    memset(mat, 63, sizeof mat);
    int inf = mat[0][0];

    for (int i = 0; i < 110; i++)
        mat[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        mat[a][b] = c;
    }

    bool neg = false;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][k] < inf and mat[k][k] < 0 and mat[k][j] < inf)
                    neg = true;
                if (mat[i][k] < inf and mat[k][j] < inf)
                    mat[i][j] = min(mat[i][k] + mat[k][j], mat[i][j]);
            }
        }
    }
    if (neg)
        cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int i = 0; i < n; i++, cout << endl) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == inf)
                    cout << "INF";
                else
                    cout << mat[i][j];
                if (j < n - 1)
                    cout << " ";
            }
        }
    }
//    dijkstra(src);
//    bellman(src);
//    init(n + 1);
//    mst();
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
