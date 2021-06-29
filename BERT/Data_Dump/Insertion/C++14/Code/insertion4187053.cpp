#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, (n))
#define REPR(i, n) FORR(i, (n) - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define REPS(c, s) for (char c : s)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REV(c) reverse(ALL(c))
#define sz(v) (int)v.size()
#define endl '\n'
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000001000000001LL;
 
void solve();
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(numeric_limits<double>::max_digits10);
    solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    auto p = [&](){REP(i, n) cout << a[i] << (i == n - 1 ? endl : ' ');};

    REP1(i, n - 1) {
        p();
        REPR(j, i) {
            if (a[j] <= a[j + 1]) break;
            swap(a[j], a[j + 1]);
        }
    }
    p();
}


