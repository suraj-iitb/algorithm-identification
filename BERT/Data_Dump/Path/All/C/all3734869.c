#include <bits/stdc++.h>
using namespace std;

// Template Headers {{{
using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long; using vll = vector<long long>;
template <class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <class T> istream &operator>>(istream &, vector<T> &);
template <class T> ostream &operator<<(ostream &, const vector<T> &);
template <class T, class U> istream &operator>>(istream &, pair<T, U> &);
template <class T, class U> ostream &operator<<(ostream &, const pair<T, U> &);
template <class T> struct Inf { static constexpr T inf() { return std::numeric_limits<T>::has_infinity() ? std::numeric_limits<T>::infinty() : std::numeric_limits<T>::max(); } };
template <> struct Inf<int> { static constexpr int inf() { return 0x3f3f3f3f; } };
template <> struct Inf<long long> { static constexpr long long inf() { return 0x3f3f3f3f3f3f3f3fLL; } };
constexpr int INF = Inf<int>::inf(); constexpr ll BINF = Inf<ll>::inf();
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// }}}
// Weighted Graph Template {{{
template <class T>
class WeGraph : public vector<vector<pair<int, T>>> {
	private:
		int n, m;
	public:
		WeGraph(int n, int m) : vector<vector<pair<int, T>>>(n), n(n), m(m) {}

		template <class U>
		friend istream &operator>>(istream &is, WeGraph<U> &g) {
			for (int i=0;i<g.m;i++) {
				int u, v; T l; is >> u >> v >> l; // u--, v--;
				g[u].emplace_back(v, l);
				// g[v].emplace_back(u, l); // comment out this line for undirected graph
			}
			return is;
		}

		void addDiEdge(int u, int v, const T &w) { (*this)[u].emplace_back(v, w); }
		void addDiEdge(int u, int v, T &&w) { (*this)[u].emplace_back(v, w); }

		void addEdge(int u, int v, const T &w) { addDiEdge(u, v, w), addDiEdge(v, u, w); }
		void addEdge(int u, int v, T &&w) { addDiEdge(u, v, w), addDiEdge(v, u, w); }

};
// }}}

int solve() {
	int n, m; cin >> n >> m;
	vector<vll> dp(n, vll(n, BINF));
	for (int i=0;i<n;i++) dp[i][i] = 0;
	for (int i=0;i<m;i++) {
		int u, v; ll l; cin >> u >> v >> l;
		dp[u][v] = l;
	}

	for (int k=0;k<n;k++) for (int u=0;u<n;u++) {
		if (dp[u][k] >= BINF) continue;
		for (int v=0;v<n;v++) if (dp[k][v] < BINF)
			dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
	}
	for (int k=0;k<n;k++) for (int u=0;u<n;u++) {
		if (dp[k][u] >= BINF) continue;
		for (int v=0;v<n;v++) if (dp[u][v] < BINF && dp[k][u] + dp[u][v] < dp[k][v]) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		if (dp[i][j] >= BINF)
			cout << "INF";
		else
			cout << dp[i][j];
		cout << " \n"[j==n-1];
	}

	return 0;
}

// Template Main {{{
int main() {
	ios::sync_with_stdio(0);
	// precompute();
	// int t; cin >> t; for (int i=1;i<=t;i++)
	solve();
	// cout << "Case #" << i << ": ", solve();
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
