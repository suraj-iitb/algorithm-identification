#include <bits/stdc++.h>
using namespace std;

// Template Headers {{{
using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long; using vll = vector<long long>;
template <class T> istream &operator>>(istream &, vector<T> &);
template <class T> ostream &operator<<(ostream &, const vector<T> &);
template <class T, class U> istream &operator>>(istream &, pair<T, U> &);
template <class T, class U> ostream &operator<<(ostream &, const pair<T, U> &);
constexpr int INF = 0x3f3f3f3f; constexpr ll BINF = 0x3f3f3f3f3f3f3f3fLL;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// }}}

int solve() {
	using pli = pair<ll, int>;
	using vpli = vector<pli>;
	int n, m, r; cin >> n >> m >> r;
	vector<vpli> g(n);
	for (int i=0;i<m;i++) {
		int u, v; ll l; cin >> u >> v >> l;
		g[u].emplace_back(v, l);
	}
	vll dist(n, BINF); vi vis(n);
	priority_queue<pli, vpli, greater<pli>> q;
	dist[r] = 0; q.emplace(dist[r] = 0, r);
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto p : g[u]) {
			int v = p.first; ll t = dist[u] + p.second;
			if (t < dist[v]) q.emplace(dist[v] = t, v);
		}
	}
	for (ll d : dist) if (d != BINF)
		cout << d << endl;
	else
		cout << "INF" << endl;
	return 0;
}

// Template Main {{{
int main() {
	ios::sync_with_stdio(0);
	// precompute();
	// int t; cin >> t; for (int i=1;i<=t;i++)
	solve();
	// cout << (solve() ? "YES" : "NO") << endl;
	return 0;
}

template <class T> istream &operator>>(istream &is, vector<T> &v) {
	for (auto it=v.begin();it!=v.end();++it) is >> *it;
	return is;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
	for (auto it=v.begin();it!=v.end();) os << *it, os << " \n"[++it==v.end()];
	return os;
}

template <class T, class U> istream &operator>>(istream &is, pair<T, U> &p) {
	return is >> p.first >> p.second;
}

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	return os << p.first << ' ' << p.second;
}
// }}}

// vim: fdm=marker
