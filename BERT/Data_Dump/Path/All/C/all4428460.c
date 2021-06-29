#include <bits/stdc++.h>
using namespace std;
template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    for (int i=0; i<(((int)(v).size())); ++i) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}
template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}
template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;
/*
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    // ifstream in("in.txt");
    // cin.rdbuf(in.rdbuf());

    return 0;
}
*/
template<typename T>
struct edge {
    int src, to;
    T cost;
};
template<typename T>
using Graph = vector<vector<edge<T>>>;
/**
 * @brief
 * 全点対間最短経路(ワーシャルフロイド)
 * O(V^3)
 * @author ?
 * @date ?
 *
 * @param[in] g グラフ(隣接行列)
 * @param[in] inf 到達不可能を表す無限値
 * @param[out] g 最短距離(隣接行列)
 *
 * @details
 * 2020/05/04 コメント追加, inf に使う値を明示的に渡す. by habara-k
 */
template<typename T>
void warshall_floyd(vector<vector<T>> &g, T inf) {
    int n = g.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] == inf or g[k][j] == inf) continue;
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<ll>> G(V, vector<ll>(V, LINF));
    for (int i = 0; i < V; ++i) G[i][i] = 0;
    for (int i = 0; i < E; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x][y] = z;
    }
    warshall_floyd(G, LINF);
    for (int i = 0; i < V; ++i) {
        if (G[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j > 0) putchar(' ');
            if (G[i][j] == LINF) printf("INF");
            else printf("%d", G[i][j]);
        }
        putchar('\n');
    }
}
