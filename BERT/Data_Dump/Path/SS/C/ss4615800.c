#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <numeric>
#include <string>
#include <bitset>

/*----------------------------------------------------------------*/

using ld = long double;
using vld = std::vector<ld>;
using vvld = std::vector<vld>;
using vvvld = std::vector<vvld>;
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using str = std::string;
using vstr = std::vector<str>;

/*----------------------------------------------------------------*/

template<typename T> bool chmin(T a, T &b) { return a < b ? b = a, true : false; }
template<typename T> bool chmax(T a, T &b) { return a > b ? b = a, true : false; }
template<typename T> T rpow(T a, ll n) {
    if (n == 0) return 1;
    T k = 1;
    for (; n > 1; n >>= 1) {
        if (n & 1) k *= a;
        a *= a;
    }
    return k * a;
}

/*----------------------------------------------------------------*/

constexpr ld PI = 3.141592653589793L;
constexpr ld EPS = std::numeric_limits<ld>::epsilon();

/*----------------------------------------------------------------*/

ll gcd(ll n, ll m) { return m ? gcd(m, n % m) : n; }
ll lcm(ll n, ll m) { return n / gcd(n, m) * m; }
bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; rpow(i, 2) <= n; i++)
        if (n % i == 0) return false;
    return true;
}

/*----------------------------------------------------------------*/

struct edge {
    ll to, cost;

    edge(ll t, ll d) {
        to = t, cost = d;
    }
};
void solve();

/*----------------------------------------------------------------*/

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::setprecision(15);

    solve();
}

void solve() {
    ll v, e, r;
    std::cin >> v >> e >> r;

    std::vector<std::vector<edge>> g(v);
    for (ll i = 0; i < e; i++) {
        ll s, t, d;
        std::cin >> s >> t >> d;
        g[s].push_back(edge(t, d));
    }

    vll dist(v, 1e12);

    auto dijkstra = [&](ll s) {
        dist[s] = 0;
        std::priority_queue<std::pair<ll, ll>,
                            std::vector<std::pair<ll, ll>>,
                            std::greater<std::pair<ll, ll>>> que;
        que.push({ 0, s });

        while (!que.empty()) {
            std::pair<ll, ll> p = que.top();
            que.pop();
            ll cur_v = p.second;
            if (dist[cur_v] < p.first) continue;
            for (edge i : g[cur_v])
                if (chmin(dist[cur_v] + i.cost, dist[i.to]))
                    que.push({ dist[i.to], i.to });
        }
    };

    dijkstra(r);

    for (ll i : dist)
        if (i < 1e12) std::cout << i << '\n';
        else std::cout << "INF" << '\n';
}

