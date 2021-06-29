#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define rrep(i, n) for(int i=(n)-1; i>=0; --i)
#define rfor(i, m, n) for(int i=(m); i>=(n); --i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
using LL = long long;		using VB = vector<bool>;
using VI = vector<int>;		using VL = vector<LL>;
using VS = vector<string>;	using VD = vector<double>;
using VVI = vector<VI>;		using VVL = vector<VL>;
using PII = pair<int, int>;	using PLL = pair<LL, LL>;
using VP = vector<PII>;		using VPL = vector<PLL>;
const int inf = (int)1e9;
const LL inf_ll = (LL)1e18, MOD = 1000000007;
const double PI = acos(-1.0), EPS = 1e-12;

template<class T>inline void Sort(T& a)noexcept { sort(all(a)); }
template<class T>inline void RSort(T& a)noexcept { sort(rall(a)); }
template<class T>inline void Reverse(T& a)noexcept { reverse(all(a)); }
template<class T>inline void Unique(T& a)noexcept { a.erase(unique(all(a)), a.end()); }
template<class T>inline T Sorted(T a)noexcept { Sort(a); return a; }
template<class T>inline T RSorted(T a)noexcept { RSort(a); return a; }
template<class T>inline T Reversed(T a)noexcept { Reverse(a); return a; }
template<class T>inline T Uniqued(T a)noexcept { Unique(a); return a; }
template<class T>inline auto Max(const T& a)noexcept { return *max_element(all(a)); }
template<class T>inline auto Min(const T& a)noexcept { return *min_element(all(a)); }
template<class T>inline int MaxPos(const T& a)noexcept { return max_element(all(a)) - a.begin(); }
template<class T>inline int MinPos(const T& a)noexcept { return min_element(all(a)) - a.begin(); }
template<class T, class U>inline int Count(const T& a, const  U& v)noexcept { return count(all(a), v); }
template<class T, class U>inline int Find(const T& a, const U& v)noexcept { auto pos = find(all(a), v); return pos == a.end() ? -1 : pos - a.begin(); }
template<class T, class U>inline U Sum(const T& a, const U& v)noexcept { return accumulate(all(a), v); }
template<class T, class U>inline int Lower(const T& a, const U& v)noexcept { return lower_bound(all(a), v) - a.begin(); }
template<class T, class U>inline int Upper(const T& a, const U& v)noexcept { return upper_bound(all(a), v) - a.begin(); }
template<class T, class P>inline void RemoveIf(T& a, P f)noexcept { a.erase(remove_if(all(a), f), a.end()); }
template<class T>inline T Age(T n, T m)noexcept { return (n + m - 1) / m; }
template<class T>inline T Age2(T n, T m)noexcept { return Age(n, m) * m; }
template<class T>inline T Tri(T n)noexcept { return (n & 1) ? (n + 1) / 2 * n : n / 2 * (n + 1); }
template<class T>inline T Gcd(T n, T m)noexcept { return m ? Gcd(m, n % m) : n; }
template<class T>inline T Lcm(T n, T m)noexcept { return n / Gcd(n, m) * m; }
template<class T>inline T Pow(T a, T n)noexcept { T r = 1; while (n > 0) { if (n & 1)r *= a; a *= a; n /= 2; }return r; }
template<class T>inline T Powmod(T a, T n, T m = MOD)noexcept { T r = 1; while (n > 0) { if (n & 1)r = r * a % m, n--; else a = a * a % m, n /= 2; }return r; }
template<class T>inline bool chmax(T& a, const T& b)noexcept { if (a < b) { a = b; return true; } return false; }
template<class T>inline bool chmin(T& a, const T& b)noexcept { if (a > b) { a = b; return true; } return false; }
inline string operator*(string s, int n)noexcept { string ret; rep(i, n)ret += s; return ret; }

// --- input --- //
#if defined(_MSC_VER) || defined(ONLINE_JUDGE)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
inline int gc()noexcept { return getchar_unlocked(); }
template<class T>inline void InputF(T& v)noexcept { cin >> v; }
inline void InputF(char& v)noexcept { while (isspace(v = gc())); }
inline void InputF(string& v)noexcept {
	char c; for (InputF(c); !isspace(c); c = gc())v += c;
}
inline void InputF(int& v)noexcept {
	bool neg = false; v = 0; char c; InputF(c);
	if (c == '-') { neg = true; c = gc(); }
	for (; isdigit(c); c = gc())v = v * 10 + (c - '0');
	if (neg)v = -v;
}
inline void InputF(long long& v)noexcept {
	bool neg = false; v = 0; char c; InputF(c);
	if (c == '-') { neg = true; c = gc(); }
	for (; isdigit(c); c = gc())v = v * 10 + (c - '0');
	if (neg)v = -v;
}
inline void InputF(double& v)noexcept {
	double dp = 1; bool neg = false, adp = false; v = 0; char c; InputF(c);
	if (c == '-') { neg = true; c = gc(); }
	for (; isdigit(c) || c == '.'; c = gc()) {
		if (c == '.')adp = true;
		else if (adp)v += (c - '0') * (dp *= 0.1);
		else v = v * 10 + (c - '0');
	}
	if (neg)v = -v;
}
template<class T, class U>inline void InputF(pair<T, U>& v)noexcept {
	InputF(v.first); InputF(v.second);
}
template<class T>inline void InputF(vector<T>& v)noexcept {
	for (auto& e : v)InputF(e);
}
struct InputV {
	int n, m;
	InputV(int N) :n(N), m(0) {}
	InputV(pair<int, int> N) :n(N.first), m(N.second) {}
	template<class T>operator vector<T>()noexcept {
		vector<T> v(n); InputF(v); return v;
	}
	template<class T>operator vector<vector<T>>()noexcept {
		vector<vector<T>> v(n, vector<T>(m)); InputF(v); return v;
	}
};
struct Input {
	template<class T>operator T()noexcept { T v; InputF(v); return v; }
	int operator--(int) { int v; InputF(v); v--; return v; }
	InputV operator[](int n)noexcept { return InputV(n); }
	InputV operator[](pair<int, int> n)noexcept { return InputV(n); }
	template<class T, size_t W>array<vector<T>, W> get(int H) {
		array<vector<T>, W> ret;
		rep(i, H)rep(j, W) { T x = *this; ret[j].push_back(x); }
		return ret;
	}
}in;

// --- output --- //
struct BoolStr {
	const char* t, * f; BoolStr(const char* _t, const char* _f) :t(_t), f(_f) {}
}Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO"), Int("1", "0");
struct DivStr {
	const char* d, * l; DivStr(const char* _d, const char* _l) :d(_d), l(_l) {}
}spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"), no_endl(" ", "");
class Output {
	BoolStr B{ Yes }; DivStr D{ spc }; bool isPrint = true;
	void p(double v) { printf("%.20f", v); } void p(long double v) { printf("%.20Lf", v); }
	void p(int v) { printf("%d", v); }	void p(LL v) { printf("%lld", v); }
	void p(char v) { putchar(v); }		void p(bool v) { printf(v ? B.t : B.f); }
	template<class T>void p(const T& v) { cout << v; }
	template<class T, class U>void p(const pair<T, U>& v) { p(v.first); printf(D.d); p(v.second); }
	template<class T>void p(const vector<T>& v) { rep(i, sz(v)) { if (i)printf(D.d); p(v[i]); } }
	template<class T>void p(const vector<vector<T>>& v) { rep(i, sz(v)) { if (i)printf(D.l); p(v[i]); } }
	void p(const BoolStr& v) { B = v; isPrint = false; } void p(const DivStr& v) { D = v; isPrint = false; }
public:
	void operator()() { printf(D.l); }
	template<class H>void operator()(H&& h) {
		p(h); if (isPrint)printf(D.l); isPrint = true; B = Yes; D = spc;
	}
	template<class H, class...T>void operator()(H&& h, T&& ...t) {
		p(h); if (isPrint)printf(D.d); isPrint = true; operator()(forward<T>(t)...);
	}
	template<class...T>void exit(T&& ...t) {
		operator()(forward<T>(t)...); std::exit(EXIT_SUCCESS);
	}
}out;

using Weight = long long;
constexpr Weight INF = numeric_limits<Weight>::max();
struct Edge {
	int to; Weight cost;
	Edge() :to(-1), cost(-1) {}
	Edge(int _to, Weight _cost = 1) :to(_to), cost(_cost) {}
};
bool operator>(const Edge& e1, const Edge& e2) { return e1.cost > e2.cost; }
struct Edge2 {
	int u, v; Weight cost;
	Edge2() :u(-1), v(-1), cost(0) {}
	Edge2(int _u, int _v, Weight _cost) :u(_u), v(_v), cost(_cost) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;
using UnWeightedGraph = vector<vector<int>>;

// --- dump --- //
#if __has_include("dump.hpp")
#include "dump.hpp"
#else
#define dump(...) (void(0))
#endif

// ------------------------------------------------------------ //

bool WarashallFloyd(Matrix& dist, Weight INF_ = INF) {
	int V = dist.size();
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			for (int k = 0; k < V; ++k) {
				if (dist[j][i] == INF_ || dist[i][k] == INF_)continue;
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
	for (int i = 0; i < V; ++i)
		if (dist[i][i] < 0)return true;
	return false;
}

int main() {
	int n = in, m = in;
	Matrix a(n, Array(n, INF));
	rep(i, n)a[i][i] = 0;
	rep(i, m) {
		int s = in, t = in; LL d = in;
		a[s][t] = d;
	}
	if (WarashallFloyd(a)) {
		out("NEGATIVE CYCLE");
	} else {
		rep(i, n) {
			rep(j, n) {
				if (j)out(no_endl, " ");
				if (a[i][j] == INF)out(no_endl, "INF");
				else out(no_endl, a[i][j]);
			}
			out();
		}
	}
}
