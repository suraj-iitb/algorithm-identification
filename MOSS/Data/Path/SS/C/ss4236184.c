#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
#define deps(i, E, S) for (ll i = (E); i >= (S); i--)
#define dep(i, N) deps(i, N-1, 0)
const ll INF = 1LL << 60;
const int INF_INT = 1 << 30;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
struct mll {
	static ll MOD;
	ll val;
	mll(ll v = 0) : val(v % MOD) { if (val < 0) val += MOD; }
	mll operator - () const { return -val; }
	mll operator + (const mll &b) const { return val + b.val; }
	mll operator - (const mll &b) const { return val - b.val; }
	mll operator * (const mll &b) const { return val * b.val; }
	mll operator / (const mll &b) const { return mll(*this) /= b; }
	mll operator + (ll b) const { return *this + mll(b); }
	mll operator - (ll b) const { return *this - mll(b); }
	mll operator * (ll b) const { return *this * mll(b); }
	friend mll operator + (ll a, const mll &b) { return b + a; }
	friend mll operator - (ll a, const mll &b) { return -b + a; }
	friend mll operator * (ll a, const mll &b) { return b * a; }
	mll &operator += (const mll &b) { val = (val + b.val) % MOD; return *this; }
	mll &operator -= (const mll &b) { val = (val + MOD - b.val) % MOD; return *this; }
	mll &operator *= (const mll &b) { val = (val*b.val) % MOD; return *this; }
	mll &operator /= (const mll &b) {
		ll c = b.val, d = MOD, u = 1, v = 0;
		while (d) {
			ll t = c / d;
			c -= t * d; swap(c, d);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll &operator += (ll b) { return *this += mll(b); }
	mll &operator -= (ll b) { return *this -= mll(b); }
	mll &operator *= (ll b) { return *this *= mll(b); }
	mll &operator /= (ll b) { return *this /= mll(b); }
	bool operator == (const mll &b) { return val == b.val; }
	bool operator != (const mll &b) { return val != b.val; }
	bool operator == (ll b) { return *this == mll(b); }
	bool operator != (ll b) { return *this != mll(b); }
	friend bool operator == (ll a, const mll &b) { return mll(a) == b.val; }
	friend bool operator != (ll a, const mll &b) { return mll(a) != b.val; }
	friend ostream &operator << (ostream &os, const mll &a) { return os << a.val; }
	friend istream &operator >> (istream &is, mll &a) { return is >> a.val; }
	static mll Combination(ll a, ll b) {
		chmin(b, a - b);
		if (b < 0) return mll(0);
		mll c = 1;
		rep(i, b) c *= a - i;
		rep(i, b) c /= i + 1;
		return c;
	}
};
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;

struct Fast {
	Fast() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast; //cin,cout高速化のおまじない＋桁数指定

ll mll::MOD = (ll)(1e9 + 7);// 998244353ll;


//◆--↓--グラフテンプレート--↓--
template<typename T>
struct edge {
	ll src, to;
	T cost;
	edge(ll to, T cost) : src(-1), to(to), cost(cost) {}
	edge(ll src, ll to, T cost) : src(src), to(to), cost(cost) {}
	edge &operator=(const ll &x) {
		to = x;
		return *this;
	}
	operator ll() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<ll>>;
template<typename T>
using Matrix = vector<vector<T >>;
//--↑--グラフテンプレート--↑--

//◆--↓--ダイクストラ：O(E * logV)--↓--
template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, ll s) {
	const auto INF = numeric_limits< T >::max();
	vector< T > dist(g.size(), INF);

	using Pi = pair< T, ll >;
	priority_queue< Pi, vector< Pi >, greater< Pi > > que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while (!que.empty()) {
		T cost;
		ll idx;
		tie(cost, idx) = que.top();
		que.pop();
		if (dist[idx] < cost) continue;
		for (auto &e : g[idx]) {
			auto next_cost = cost + e.cost;
			if (dist[e.to] <= next_cost) continue;
			dist[e.to] = next_cost;
			que.emplace(dist[e.to], e.to);
		}
	}
	return dist;
}
//--↑--ダイクストラ--↑--

int main() {
	ll V;
	cin >> V;
	ll E;
	cin >> E;
	ll R;
	cin >> R;

	//usage
	//int V, E, R;
	//scanf("%d %d %d", &V, &E, &R);
	//WeightedGraph<ll> g(V);
	//for (int i = 0; i < E; i++) {
	//	int a, b, c;
	//	scanf("%d %d %d", &a, &b, &c);
	//	g[a].emplace_back(b, c);
	//}
	//vector<int> distance = dijkstra(g, R); //R:start point

	WeightedGraph<ll> g(V);
	rep(i, E) {
		ll A;
		cin >> A;
		ll B;
		cin >> B;
		ll C;
		cin >> C;
		g[A].emplace_back(B, C);
	}

	auto distance = dijkstra(g, R);

	rep(i, V) {
		ll result = distance[i];

		if (result == numeric_limits<ll>::max()) {
			cout << "INF" << endl;
		}
		else {
			cout << result << endl;
		}
	}

	return 0;
}
