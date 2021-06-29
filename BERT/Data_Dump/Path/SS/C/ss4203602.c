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

template <typename T>
vector<T> Dijkstra(int s, vector<vector<pair<int, T>>>& g) {
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>
        que;
    int n = sz(g);
    vector<T> d(n);
    rep(i, n) d[i] = LINF;
    d[s] = 0;
    que.push(make_pair(0LL, s));
    while (!que.empty()) {
        pair<T, int> p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (auto e : g[v]) {
            if (chmin(d[e.first], d[v] + e.second)) {
                que.push(make_pair(d[e.first], e.first));
            }
        }
    }
    return d;
}
int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<pair<int, ll>>> g(n);
    rep(i, m) {
        int s, t;
        ll d;
        cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    auto d = Dijkstra(r, g);
    rep(i, n) {
        if (d[i] == LINF)
            cout << "INF" << endl;
        else
            cout << d[i] << endl;
    }
}
