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

int n, m, r;
vector<pair<int, int>> G[100009];
ll d[100009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> r;

    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b, c);
    }

    rep(i, n) d[i] = inf;
    d[r] = 0;
    priority_queue<pair<int, int>> q;
    q.emplace(0, r);

    while(!q.empty()) {
        int dist = -q.top().first;
        int v = q.top().second;
        q.pop();
        if(d[v] < dist) continue;
        for(auto p : G[v]) {
            int cost = p.second;
            int to = p.first;
            if(chmin(d[to], dist + cost)) q.emplace(-d[to], to);
        }
    }

    rep(i, n) {
        if(d[i] < inf)
            cout << d[i] << "\n";
        else
            cout << "INF\n";
    }

    return 0;
}
