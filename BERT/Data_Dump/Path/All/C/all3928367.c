#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

// ワーシャルフロイド法 O(V^3)
template<typename T>
struct Warshall_floyd {
private:
    int V; // 頂点数
    vector<vector<T>> d; // i から j の最短距離
public:
    T inf = numeric_limits<T>::max();

    Warshall_floyd(int V) : V(V) {
        d.resize(V, vector<T>(V, inf));
        for (int i = 0; i < V; i++) {
            d[i][i] = 0;
        }
    }
    void add_edge(int from, int to, int cost, bool directed = false) {
        d[from][to] = cost;
        if (!directed) d[to][from] = cost;
    }

    void warshall_floyd() {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (d[i][k] != inf && d[k][j] != inf) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
    }

    // from から to の距離
    // d[i][i] < 0 の時は負閉路
    T dist(int from, int to) {
        return d[from][to];
    }
};

int main() {
    int v, e; cin >> v >> e;
    Warshall_floyd<ll> G(v);
    REP(i, e) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        G.add_edge(a, b, c, true);
    }
    G.warshall_floyd();
    REP(i, v) if (G.dist(i, i) < 0) {
        puts("NEGATIVE CYCLE");
        return 0;
    }
    REP(i, v) {
        REP(j, v) {
            if (G.dist(i, j) == G.inf) cout << "INF";
            else cout << G.dist(i, j);
            if (j == v - 1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}
