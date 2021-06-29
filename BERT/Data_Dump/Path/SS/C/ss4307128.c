// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep4(i, a, b, c) for (int i = int(a), i##__b = int(b), i##__c = int(c); i < i##__b; i += i##__c)
#define rep1(n) rep4(i, 0, n, 1)
#define rep2(i, n) rep4(i, 0, n, 1)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define REP(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep3(i, a, b) for (int i = int(b) - 1, i##__a = int(a); i >= i##__a; i--)
#define rrep1(n) rrep3(i, 0, n)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep4(i, a, b, c) for (int i = int(a + (b - a - 1) / c * c), i##__a = int(a), i##__c = int(c); i >= i##__a; i -= i##__c)
#define RREP(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define FOR(i, x) for (auto &i : x)
#define ALL(v) (v.begin()), (v.end())
#define pb(x) emplace_back(x)
#define mp(x, y) make_pair(x, y)
#define mt make_tuple
#define endl '\n'
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using vstring = vector<string>;
template <class T> using vv = vector<vector<T>>;
template <class T> using pq = priority_queue<T>;
template <class T> using rpq = priority_queue<T, vector<T>, greater<T>>;
#define vvint(A, H, W) vvint A(H, vint(W))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const ll LINF = 1e18;
template <class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return 1;}return 0;}
template <class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return 1;}return 0;}
#define print(x){cout<<x<<endl;}
// clang-format on

int main() {
    int v, e, r;
    cin >> v >> e >> r;
    vv<pii> edge_to_d(v);
    REP(e) {
        int s, t, d;
        cin >> s >> t >> d;
        edge_to_d[s].pb(mp(t, d));
    }
    vll ans(v, LINF);
    ans[r] = 0;
    // q : (暫定最短距離, 最短であると確定している頂点に接する頂点)の集まり
    // 取り出したものは最短確定
    // 今の頂点に接する頂点のうち、暫定最短距離を更新できるなら候補として(暫定最短距離, その頂点)を追加
    //     (更新しないほうが良ければ、取り出すだけで終了)
    rpq<pll> q;
    q.push(mp(0, r));
    while (!q.empty()) {
        ll nowd, now;
        tie(nowd, now) = q.top();
        q.pop();
        FOR(to, edge_to_d[now]) {
            int t, d;
            tie(t, d) = to;
            if (chmin(ans[t], nowd + d)) {
                q.push(mp(nowd + d, t));
            }
        }
    }
    REP(v) {
        if (ans[i] == LINF) {
            print("INF");
        } else {
            print(ans[i]);
        }
    }
}

