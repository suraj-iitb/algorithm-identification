#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    ll V, E;
    cin >> V >> E;
    Graph graph(V, vector<ll>(V, INF));
    rep(i, E) {
        ll s, t, d;
        cin >> s >> t >> d;
        graph[s][t] = d;
    }
    rep(k, V) {
        rep(i, V) {
            rep(j, V) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
    bool ok = false;
    rep(k, V) {
        if (graph[k][k] < 0) ok = true;
    }
    if (ok) {
        cout << "NEGATIVE CYCLE" << '\n';
        return;
    }
    rep(i, V) {
        rep(j, V) {
            ll ans = graph[i][j];
            if (i == j) ans = 0;
            if (j > 0)cout << ' ';
            if (ans <= INF && ans >= INF / 2) {
                cout << "INF";
            } else {
                cout << ans;
            }
        }
        cout << '\n';
    }
}

//0 1 3 4
//INF 0 2 3
//INF INF 0 1
//INF INF 7 0
//0 1 3 4
//INF 0 2 3
//INF INF 0 1
//INF INF 7 0
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

