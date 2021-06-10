#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
using pint = pair<ll, ll>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n, k;
    cin >> n >> k;
    ll g[n][n];
    rep(i, 0, n) rep(j, 0, n) g[i][j] = INF;
    rep(i, 0, k) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s][t] = d;
    }
    rep(i, 0, n) g[i][i] = 0;
    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    rep(i, 0, n) {
        if (g[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            if (g[i][j] > 1e15) {
                cout << "INF";
            } else {
                cout << g[i][j];
            }
            if (j != n - 1) cout << " ";
        }
        cout << "\n";
    }
}
