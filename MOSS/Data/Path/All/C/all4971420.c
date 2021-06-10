#include <bits/stdc++.h>
#define int long long

struct edge { int to; int cost; };
using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using ge = vector<vector<edge>>;
using gi = vector<vector<int>>;
// using mint = modint1000000007;
// using mint = modint998244353;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ")
#define print1(v) cout << fixed << setprecision(10) << v << "\n"
#define print2(v1, v2) cout << fixed << setprecision(10) << v1 << " " << v2 << "\n"
#define print3(v1, v2, v3) cout << fixed << setprecision(10) << v1 << " " << v2 << " " << v3 << "\n"
#define printvi(v, n) REP(iiii, n) { cout << v[iiii]; delim(iiii, n); }
#define printvii(v, h, w) REP(iiiii, h) { printvi(v[iiiii], w); }

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 100;
int n, m;
vii dist(maxn);

void warshall_floyd() {
    REP(i, n) {
        REP(j, n) {
            REP(k, n) {
                if (dist[j][i] == inf || dist[i][k] == inf) continue;
                // min(inf, inf + (N<0)) should be inf but not
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

signed main () {
	cin.tie(0);
    ios::sync_with_stdio(false);

    // https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C
    cin >> n >> m;

    REP(i, n) {
        REP(j, n) {
            dist[i].push_back(inf);
        }
    }
    REP(i, n) dist[i][i] = 0;

    REP(i, m) {
        int s, t, d; cin >> s >> t >> d;
        dist[s][t] = d;
    }

    warshall_floyd();

    bool flag = false;
    REP(i, n) {
        if (dist[i][i] < 0) {
            flag = true;
            break;
        }
    }
    if (flag) print1("NEGATIVE CYCLE");
    else {
        REP(i, n) {
            REP(j, n) {
                if (dist[i][j] == inf) cout << "INF";
                else cout << dist[i][j];
                delim(j, n);
            }
        }
    }

}

