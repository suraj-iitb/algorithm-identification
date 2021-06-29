#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
const ll INF = 1e18;
const int INT_INF = 1e9;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int v, e;

int main() {
    cin >> v >> e;

    // Adjacency matrix
    vector<vector<ll>> g(v);
    rep(i, v) g[i].resize(v);
    // initialization
    rep(i, v) {
        rep(j, v) {
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }

    rep(i, e) {
        int s, t; ll d;
        cin >> s >> t >> d;
        g[s][t] = d;
    }

    // Warshall-Floyd
    rep(k, v) {
        rep(i, v) {
            rep(j, v) {
                if (g[i][k] != INF && g[k][j] != INF) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    // Check if negative cycle exists
    rep(i, v) {
        if (g[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, v) {
        rep(j, v) {
            ll c = g[i][j];
            if (c == INF) cout << "INF";
            else cout << c;
            if (j < v-1) cout << ' ';
        }
        cout << endl;
    }
}

