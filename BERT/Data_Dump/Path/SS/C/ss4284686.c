#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>
#include <string>
#include <bitset>
#include <functional>

using namespace std;
using lint = long long;
using vi = vector<int>;
using vl = vector<int>;
using pii = pair<int, int>;
using pll = pair<lint, lint>;
using pqi = priority_queue<int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n); i > 0; i--)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define mp(x, y) make_pair((x), (y))
#define all(x) (x).begin(), (x).end()
#define foreach(it, x) for (auto it = (x).begin(); it != (x).end(); it++)
#define space (char)0x20

constexpr lint MOD = 1e9 + 7;
int A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
// int ans;
// string ans;

struct Edge {
    int to;
    int cost;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E >> R;
    vector<vector<Edge>> edge(V);
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        edge[s].push_back({ t, d });
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vi w(V, INT32_MAX);
    w[R] = 0;
    pq.push({ 0, R });
    while (!pq.empty()) {
        auto c = pq.top(); pq.pop();
        if (w[c.second] < c.first) {
            continue;
        }
        for (auto i : edge[c.second]) {
            if (w[i.to] > w[c.second] + i.cost) {
                w[i.to] = w[c.second] + i.cost;
                pq.push({ w[i.to], i.to});
            }
        }
    }

    foreach(it, w) {
        if (*it != INT32_MAX) cout << *it << endl;
        else cout << "INF" << endl;
    }

	return 0;
}
