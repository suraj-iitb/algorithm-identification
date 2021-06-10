#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const ll INF = 1e18;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, m;
    cin >> n >> m;
    ll d[n][n] = {};
    rep(i, 0, n) rep(j, 0, n) d[i][j] = INF;
    rep(i, 0, n) d[i][i] = 0;
    rep(i, 0, m) {
        ll s, t, c;
        cin >> s >> t >> c;
        d[s][t] = c;
    }
    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                if (d[i][k] == INF || d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    rep(i, 0, n) {
        if (d[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (d[i][j] == INF) cout << "INF";
            else cout << d[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

