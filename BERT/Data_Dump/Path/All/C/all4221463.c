#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(unique(all(x)), x.end());
typedef long long ll;
typedef complex<double> Complex;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
vector<ll> BellmanFord(int s, vector<vector<pair<ll, ll>>>& graph) {
    int n = sz(graph);
    vector<ll> dist(n, LINF);
    dist[s] = 0;
    rep(i, n - 1) {
        rep(from, n) {
            for (auto p : graph[from]) {
                int to = p.first;
                ll cost = p.second;
                chmin(dist[to], dist[from] + cost);
            }
        }
    }
    rep(i, n) {
        rep(from, n) {
            for (auto p : graph[from]) {
                int to = p.first;
                ll cost = p.second;
                if (dist[to] > dist[from] + cost) {
                    dist[to] = -LINF;
                }
            }
        }
    }
    return dist;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    rep(i, m) {
        int s, t;
        ll x;
        cin >> s >> t >> x;
        g[s].emplace_back(t, x);
    }

    auto ans = make_vec<string>(n, n);
    rep(i, n) {
        auto bf = BellmanFord(i, g);
        rep(j, n) {
            if (bf[j] == -LINF) {
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
            }
            if (bf[j] >= LINF / 2) {
                ans[i][j] = "INF";
            } else {
                ans[i][j] = to_string(bf[j]);
            }
        }
    }

    rep(i, n) rep(j, n) cout << ans[i][j] << " \n"[j == n - 1];
}
