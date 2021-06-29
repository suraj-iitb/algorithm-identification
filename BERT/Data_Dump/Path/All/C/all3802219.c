#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007で割った余り
const long long mod = 1e9 + 7;

using ll  = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
// #define SORT(v, n) stable_sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

static const int MAX = 100;
static const ll  INF = (1LL << 32);

int n;
ll  d[MAX][MAX];

void floyd() {
    rep(k, n) {
        rep(i, n) {
            if (d[i][k] == INF) continue;
            rep(j, n) {
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(5);

    int e, u, v, c;
    cin >> n >> e;

    rep(i, n) {
        rep(j, n) { d[i][j] = ((i == j) ? 0 : INF); }
    }
    rep(i, e) {
        cin >> u >> v >> c;
        d[u][v] = c;
    }

    floyd();

    bool negative                       = false;
    rep(i, n) if (d[i][i] < 0) negative = true;

    if (negative) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i, n) {
            rep(j, n) {
                if (j) cout << " ";
                if (d[i][j] == INF)
                    cout << "INF";
                else
                    cout << d[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}

