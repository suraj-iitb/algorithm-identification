#include<bits/stdc++.h>
#define roop(i, n, m) for(int i = n; i < (int)m; i++)
#define rep(i, n) roop(i, 0, n)
#define all(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = std::int_fast64_t;
using pi = pair<ll, ll>;
const static ll inf = 1000000000;
const static ll mod = 1000000007;
const static long double eps = 1e-15;
template<typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> p) {
	os << to_string(p.first) << " " << to_string(p.second);
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
	rep(i, v.size()) {
		if(i) os << " ";
		os << to_string(v[i]);
	}
	return os;
}

// number
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
struct modint {
	ll n;
public:
	modint(const ll n = 0) : n((n % mod + mod) % mod) {}
	static modint pow(modint a, int m) {
		modint r = 1;
		while(m > 0) {
			if(m & 1) { r *= a; }
			a = (a * a); m /= 2;
		}
		return r;
	}
	modint &operator++() { *this += 1; return *this; }
	modint &operator--() { *this -= 1; return *this; }
	modint operator++(int) { modint ret = *this; *this += 1; return ret; }
	modint operator--(int) { modint ret = *this; *this -= 1; return ret; }
	modint operator~() const { return (this -> pow(n, mod - 2)); } // inverse
	friend bool operator==(const modint& lhs, const modint& rhs) {
		return lhs.n == rhs.n;
	}
	friend bool operator<(const modint& lhs, const modint& rhs) {
		return lhs.n < rhs.n;
	}
	friend bool operator>(const modint& lhs, const modint& rhs) {
		return lhs.n > rhs.n;
	}
	friend modint &operator+=(modint& lhs, const modint& rhs) {
		lhs.n += rhs.n;
		if (lhs.n >= mod) lhs.n -= mod;
		return lhs;
	}
	friend modint &operator-=(modint& lhs, const modint& rhs) {
		lhs.n -= rhs.n;
		if (lhs.n < 0) lhs.n += mod;
		return lhs;
	}
	friend modint &operator*=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * rhs.n) % mod;
		return lhs;
	}
	friend modint &operator/=(modint& lhs, const modint& rhs) {
		lhs.n = (lhs.n * (~rhs).n) % mod;
		return lhs;
	}
	friend modint operator+(const modint& lhs, const modint& rhs) {
		return modint(lhs.n + rhs.n);
	}
	friend modint operator-(const modint& lhs, const modint& rhs) {
		return modint(lhs.n - rhs.n);
	}
	friend modint operator*(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * rhs.n);
	}
	friend modint operator/(const modint& lhs, const modint& rhs) {
		return modint(lhs.n * (~rhs).n);
	}
};
istream& operator>>(istream& is, modint m) { is >> m.n; return is; }
ostream& operator<<(ostream& os, modint m) { os << m.n; return os; }
using mi = modint;
struct binomial_coefficient {
private:
	int m;
	vector<modint> fact;
public:
	binomial_coefficient(int m) : m(m) {
		fact.resize(m);
		fact[0] = 1;
		for(int i = 1; i < m; i++) fact[i] = fact[i - 1] * i;
	}
	modint combination(int n, int k) {
		if(n < 0 || k < 0 || n < k) return 0;
		return fact[n] / fact[n - k] / fact[k];
	}
};
using bic = binomial_coefficient;

// graph
using weight = long long;
struct edge { int to; weight w; };
template<typename T>
struct valued_edge { int to; weight w; T val; };
struct graph {
protected:
	int n;
	vector<vector<edge>> g;
	bool weighted;
	bool t;
public:
	graph(int n, bool t = false) : n(n), g(vector<vector<edge>>(n)), weighted(false), t(t){ }
	int size() { return n; }
	bool isweighted() { return weighted; }
	bool istree() { return t; }
	vector<edge>& operator[] (int i) {
		return g[i];
	}
	void add_edge(int s, int t, weight w = 1) {
		g[s].push_back({t, 1});
		g[t].push_back({s, 1});
		if(w != 1) weighted = true;
	}
	void add_dedge(int s, int t, weight w = 1) {
		g[s].push_back({t, w});
		if(w != 1) weighted = true;
	}
};
template<typename T>
struct valued_graph : graph {
protected:
	vector<vector<valued_edge<T>>> vg;
public:
	valued_graph(int n, bool t) : graph(n, t), vg(vector<vector<valued_edge<T>>>(n)) { }
	vector<valued_edge<T>>& operator[] (int i) {
		return vg[i];
	}
	void add_edge(int s, int t, T val, weight w = 1) {
		g[s].push_back({t, 1});
		g[t].push_back({s, 1});
		vg[s].push_back({t, 1, val});
		vg[t].push_back({s, 1, val});
		if(w != 1) weighted = true;
	}
	void add_dedge(int s, int t, T val, weight w = 1) {
		g[s].push_back({t, w});
		vg[s].push_back({t, 1, val});
		if(w != 1) weighted = true;
	}
};
vector<ll> shortest_path(graph& g, int s) {
	int n = g.size();
	vector<ll> path(n, -1);
	if(g.isweighted()) { // dijkstra
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
		path[s] = 0;
		q.push({0, s});
		while(!q.empty()) {
			ll cost = q.top().first;
			int p = q.top().second;
			q.pop();
			if(path[p] != cost) continue;
			for(auto e: g[p]) {
				if(path[e.to] == -1 || path[e.to] > cost + e.w) {
					path[e.to] = cost + e.w;
					q.push({path[e.to], e.to});
				}
			}
		}
	} else { // bfs
		queue<int> q;
		path[s] = 0;
		q.push(s);
		while(!q.empty()) {
			int p = q.front();
			q.pop();
			for(auto e: g[p]) {
				if(path[e.to] == -1) {
					path[e.to] = path[p] + 1;
					q.push(e.to);
				}
			}
		}
	}
	return path;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int v, e, r;
	cin >> v >> e >> r;
	graph g(v);
	rep(i, e) {
		int s, t, d;
		cin >> s >> t >> d;
		g.add_dedge(s, t, d);
	}
	vector<ll> path = shortest_path(g, r);
	ll ans = 0;
	rep(i, v) {
		if(path[i] == -1) cout << "INF" << "\n";
		else cout << path[i] << "\n";
	}
	return 0;
}

// ---------------------------------------

