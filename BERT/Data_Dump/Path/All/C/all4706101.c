#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

int n, m;
ll d[109][109];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    rep(i, n) {
        rep(j, n) d[i][j] = inf;
        d[i][i] = 0;
    }

    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }

    rep(k, n) rep(i, n) rep(j, n) if(d[i][k] < inf && d[k][j] < inf)
        chmin(d[i][j], d[i][k] + d[k][j]);

    rep(i, n) if(d[i][i] < 0) {
        cout << "NEGATIVE CYCLE\n";
        return 0;
    }

    rep(i, n) rep(j, n) {
        if(d[i][j] < inf)
            cout << d[i][j];
        else
            cout << "INF";
        cout << " \n"[j == n - 1];
    }

    return 0;
}
