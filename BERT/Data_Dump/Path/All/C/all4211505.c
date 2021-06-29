#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    const ll inf = LONG_LONG_MAX / 2 - 1;
    ll v, e;
    cin >> v >> e;
    vector<vector<ll>> g(v, vector<ll>(v, inf));
    rep(i, v) g[i][i] = 0;
    rep(i, e) {
        ll s, t, d;
        cin >> s >> t >> d;
        g[s][t] = d;
    }
    rep(i, v) {
        rep(j, v) {
            rep(k, v) {
                if ((g[j][i] == inf) || (g[i][k] == inf)) continue;
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }
    rep(i, v) {
        rep(j, v) {
            rep(k, v) {
                if ((g[j][i] == inf) || (g[i][k] == inf)) continue;
                if (g[j][k] > g[j][i] + g[i][k]) {
                    cout << "NEGATIVE CYCLE" << endl;
                    return 0;
                }
            }
        }
    }
    rep(i, v) {
        rep(j, v) {
            string val = (g[i][j] == inf) ? "INF" : to_string(g[i][j]);
            printf("%s%s", val.c_str(), (j == (v - 1)) ? "\n" : " ");
        }
    }
    return 0;
}

