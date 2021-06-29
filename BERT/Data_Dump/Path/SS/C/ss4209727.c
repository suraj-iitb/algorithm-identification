#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
using namespace std;

#define rep(i,n)	for(lint i = 0; i < n; i++)
#define repr(i,n)	for(lint i = n - 1; i >= 0; i--)
#define repb(i,start,end)	for(lint i = start; i <= end; i++)
#define repbr(i,start,end)	for(lint i = end; i >= start; i--)

namespace {

	using lint = long long;
	using ulint = unsigned long long;
	using ld = long double;

	template<class T>
	constexpr auto msum(T arg0)
	{
		return arg0;
	}

	template<class T, class ...Types>
	constexpr auto msum(T arg0, Types ...args)
	{
		static_assert(sizeof...(args) > 0, "arg err");

		return arg0 + msum(args...);
	}

	template<class T>
	constexpr auto mmax(T arg)
	{
		return arg;
	}

	template<class T, class ...Types>
	constexpr auto mmax(T arg0, Types ...args)
	{
		using promote_t = decltype(msum(arg0, args...));

		return max(static_cast<promote_t>(arg0), static_cast<promote_t>(mmax(args...)));
	}

	template<class T>
	constexpr auto mmin(T arg)
	{
		return arg;
	}

	template<class T, class ...Types>
	constexpr auto mmin(T arg0, Types ...args)
	{
		using promote_t = decltype(msum(arg0, args...));

		return min(static_cast<promote_t>(arg0), static_cast<promote_t>(mmin(args...)));
	}

	constexpr auto clamp(lint val, lint left, lint right)
	{
		return mmax(mmin(val, right), left);
	}

	constexpr lint div2(lint p, lint q)
	{
		return (p + q - 1) / q;
	}

	lint gcd(lint a, lint b) {
		while (1) {
			if (a < b) swap(a, b);
			if (!b) break;
			a %= b;
		}
		return a;
	}

	lint lcm(lint a, lint b)
	{
		return a / gcd(a, b) * b;
	}

	const ulint mod = 1000000007;
	const double pi = 3.141592653589793238462;
	const lint intmax = 9223372036854775807;

	struct mint
	{
		lint n;
		mint()
		{
			n = 0;
		}
		mint(lint a)
		{
			n = a % mod;
		}
		mint& operator+=(mint a)
		{
			n += a.n;
			n %= mod;
			return *this;
		}
		mint& operator-=(mint a)
		{
			n += mod;
			n -= a.n;
			n %= mod;
			return *this;
		}
		mint& operator*=(mint a)
		{
			n *= a.n;
			n %= mod;
			return *this;
		}
		mint& operator%=(mint a)
		{
			n %= a.n;
			return *this;
		}
		mint& operator++()
		{
			n++;
			n %= mod;
			return *this;
		}
		mint& operator--()
		{
			n += mod;
			n--;
			n %= mod;
			return *this;
		}
	};

	mint operator+(mint a, mint b)
	{
		a += b;
		return a;
	}
	mint operator-(mint a, mint b)
	{
		a -= b;
		return a;
	}
	mint operator*(mint a, mint b)
	{
		a *= b;
		return a;
	}

	mint factMod(lint n) {
		if (n == 0)
		{
			return 1;
		}
		mint ans = 1;
		while (n > 1) {
			ans *= n;
			n--;
		}
		return ans;
	}

	mint powMod(mint x, lint y)
	{
		if (x.n <= 1)
		{
			return x;
		}
		if (y == 0)
		{
			return 1;
		}
		else if (y == 1)
		{
			return x;
		}
		else if (y % 2 == 0)
		{
			mint tmp = powMod(x, y / 2);
			return tmp * tmp;
		}
		else
		{
			mint tmp = powMod(x, y / 2);
			return tmp * tmp * x;
		}
	}

	mint modinv(mint n)
	{
		return powMod(n, mod - 2);
	}

	vector<lint> invtbl;
	void preCalcInv(lint up)
	{
		invtbl.resize(up + 1);
		invtbl[1] = 1;
		repb(a, 2, up)
		{
			invtbl[a] = invtbl[a] = mod - invtbl[mod % a] * (mod / a) % mod;
		}
	}

	mint operator/(mint a, mint b)
	{
		if (b.n < invtbl.size())
		{
			a *= invtbl[b.n];
		}
		else
		{
			a *= modinv(b);
		}
		return a;
	}
	mint& operator/=(mint& a, mint b)
	{
		a = a / b;
		return a;
	}

	mint nCrMod(lint n, lint r)
	{
		if (n < r || n < 0 || r < 0)
		{
			return 0;
		}
		r = mmin(r, n - r);
		mint a = 1;
		repb(i, n - r + 1, n)
		{
			a *= i;
		}

		a /= factMod(r);
		return a;
	}

	mint nHrMod(lint n, lint r)
	{
		return nCrMod(n + r - 1, r);
	}

	template<class T>
	constexpr auto modK_belowN(T k, T MOD, T n)
	{
		return (n + MOD - k - 1) / MOD;
	}

	struct uf
	{
		vector<lint> p;
		vector<lint> s;

		uf(lint n) : p(n), s(n)
		{
			rep(i, n)
			{
				p[i] = i;
				s[i] = 1;
			}
		}

		lint rt(lint n)
		{
			return p[n] == n ? n : p[n] = rt(p[n]);
		}

		void un(lint n, lint m)
		{
			if (rt(n) != rt(m))
			{
				s[rt(m)] += s[rt(n)];
				p[rt(n)] = rt(m);
			}
		}

		bool eq(lint n, lint m)
		{
			return rt(n) == rt(m);
		}

		lint sz(lint n)
		{
			return s[rt(n)];
		}
	};

	template<class T>
	bool lineCol(T a1x, T a1y, T a2x, T a2y, T b1x, T b1y, T b2x, T b2y)
	{
		auto ta = (b1x - b2x) * (a1y - b1y) + (b1y - b2y) * (b1x - a1x);
		auto tb = (b1x - b2x) * (a2y - b1y) + (b1y - b2y) * (b1x - a2x);
		auto tc = (a1x - a2x) * (b1y - a1y) + (a1y - a2y) * (a1x - b1x);
		auto td = (a1x - a2x) * (b2y - a1y) + (a1y - a2y) * (a1x - b2x);

		return tc * td < 0 && ta * tb < 0;
	}

	lint powInt(lint a, lint b)
	{
		if (b == 0)
		{
			return 1;
		}
		if (b == 1)
		{
			return a;
		}
		lint tmp = powInt(a, b / 2);
		return (b % 2 == 1 ? a * tmp * tmp : tmp * tmp);
	}

	lint _sMod(string n, lint mod)
	{
		lint k = (n[0] - '0') % mod;
		for (lint i = 1; i < n.length(); i++)
		{
			k *= 10;
			k += (n[i] - '0');
			k %= mod;
		}
		return k;
	}

#define vec(name, n)			vector<lint> name(n)
#define vec_(name, n, init)		vector<lint> name(n, init)

#define vecs(name, n)			vector<string> name(n)
#define vect(t, name, n)		vector<t> name(n)

#define vec2(name, n, m)		vector<vector<lint>> name(n, vector<lint>(m))
#define vec2_(name, n, m, init)	vector<vector<lint>> name(n, vector<lint>(m, init))

	struct xy
	{
		lint x, y;
		xy() :x(0), y(0) {}
		xy(lint _x, lint _y) : x(_x), y(_y) {}
		xy operator+(const xy& p) const
		{
			return xy(x + p.x, y + p.y);
		}
		bool operator<(xy p) const
		{
			if (y == p.y)
				return x < p.x;
			return y < p.y;
		}
	};

	struct xyd
	{
		long double x, y;
		xyd() :x(0), y(0) {}
		xyd(long double _x, long double _y) : x(_x), y(_y) {}
	};

	template<class It, class T>
	bool exist(It begin, It end, const T& val)
	{
		return find(begin, end, val) != end;
	}

	template<class It, class Pr>
	bool exist_if(It begin, It end, Pr pred)
	{
		return find_if(begin, end, pred) != end;
	}

	lint ndig(lint n)
	{
		lint ans = 0;
		while (n > 0)
		{
			n /= 10;
			ans++;
		}
		return ans;
	}

	const lint alpn = 'z' - 'a' + 1;

	template<class T>
	T sgn(T val)
	{
		if (val == T(0))
			return T(0);
		if (val < 0)
			return T(-1);
		if (val > 0)
			return T(1);
	}

	template<class T>
	bool between(T val, T l, T r)
	{
		return (val >= l) && (val <= r);
	}

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

	template<class It>
	vector<lint> carr(It begin, It end) {
		vec(c, 0);
		c.push_back(1);
		auto before = *begin;
		for (auto it = begin + 1; it != end; it++) {
			if (before != *it) {
				c.push_back(0);
				before = *it;
			}
			c.back()++;
		}
		return c;
	}

	template<class T>
	struct nval {
		lint n;
		T val;
		nval() : n(0) {};
		nval(lint _n, T _val) : n(_n), val(_val) {};
	};

	template<class It>
	auto carr2(It begin, It end) {
		using T = nval<remove_reference_t<decltype(*begin)>>;

		vect(T, c, 0);
		c.push_back(T(1, *begin));
		auto before = *begin;
		for (auto it = begin + 1; it != end; it++) {
			if (before != *it) {
				c.push_back(T(0, *it));
				before = *it;
			}
			c.back().n++;
		}
		return c;
	}

	template<class It, class ...T>
	void sort2(It begin, It end, T ...p)
	{
		using val_t = remove_reference_t<decltype(*begin)>;

		sort(begin, end, [p...](val_t a, val_t b) {
			bool neq[] = { (a.*p != b.*p)... };
			bool sg[] = { (a.*p < b.*p)... };

			rep(i, sizeof...(p)) {
				if (neq[i])
				{
					return sg[i];
				}
			}
			return false;
		});
	}

	template<size_t _K, size_t _N, class ...Types, size_t ...indices>
	auto constexpr __ModKtuple_Impl(index_sequence<indices...>, tuple<Types...> args)
	{
		return make_tuple(get<indices * _N + _K>(args)...);
	}

	template<size_t K, size_t N, class ...Types>
	auto constexpr ModKtuple(Types ...args)
	{
		return __ModKtuple_Impl<K, N>(make_index_sequence<modK_belowN(K, N, sizeof...(args))>{}, forward_as_tuple(args...));
	}

	template<class It, class ...T, class ...Tsg, size_t ...indices>
	void __sort3_Impl(It begin, It end, tuple<T...> p, tuple<Tsg...> sgf, index_sequence<indices...>)
	{
		using val_t = remove_reference_t<decltype(*begin)>;

		sort(begin, end, [p, sgf](val_t a, val_t b) {
			bool neq[] = { (a.*(get<indices>(p)) != b.*(get<indices>(p)))... };
			bool sg[] = { ((a.*(get<indices>(p)) < b.*(get<indices>(p))) != (get<indices>(sgf))) ... };

			rep(i, sizeof...(indices)) {
				if (neq[i])
				{
					return sg[i];
				}
			}
			return false;
			});
	}

	template<class It, class ...T>
	void sort3(It begin, It end, T ...p)
	{
		using val_t = remove_reference_t<decltype(*begin)>;

		auto p_forward = ModKtuple<0, 2>(p...);
		auto sgf_forward = ModKtuple<1, 2>(p...);

		constexpr auto p_sz = tuple_size<decltype(p_forward)>::value;
		constexpr auto sgf_sz = tuple_size<decltype(sgf_forward)>::value;

		static_assert(p_sz == sgf_sz, "arg err");

		__sort3_Impl(begin, end, p_forward, sgf_forward, make_index_sequence<p_sz>{});
	}

	auto parr(lint n)
	{
		vector<nval<lint>> d;
		lint n_ = n;
		for (lint i = 2; i * i <= n; i++)
		{
			if (n_ % i == 0)
			{
				d.push_back(nval<lint>(1, i));
				n_ /= i;
				while (n_ % i == 0)
				{
					n_ /= i;
					d.back().n++;
				}
			}
		}
		if (n_ > 1)
		{
			d.push_back(nval<lint>(1, n_));
		}
		return d;
	}

	auto dist_1(xy p, xy q) {
		return abs(p.x - q.x) + abs(p.y - q.y);
	}
	auto dist_2(xy p, xy q) {
		return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
	}
	auto dist_2(xyd p, xyd q) {
		return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
	}
	auto dist_inf(xy p, xy q) {
		return mmax(abs(p.x - q.x), abs(p.y - q.y));
	}

	xyd center3p(xyd p[]) {
		xyd ans;

		long double a = p[0].x, b = p[0].y, c = p[1].x, d = p[1].y, e = p[2].x, f = p[2].y;

		long double aa = a * a, bb = b * b, cc = c * c, dd = d * d, ee = e * e, ff = f * f;

		ans.y = ((e - a) * (aa + bb - cc - dd) - (c - a) * (aa + bb - ee - ff)) / (2 * (e - a) * (b - d) - 2 * (c - a) * (b - f));

		if (c == a) {
			ans.x = (2 * (b - f) * ans.y - aa - bb + ee + ff) / (2 * (e - a));
		}
		else
		{
			ans.x = (2 * (b - d) * ans.y - aa - bb + cc + dd) / (2 * (c - a));
		}

		return ans;
	}

	lint fact(lint n) {
		if (n == 0)
		{
			return 1;
		}
		lint ans = 1;
		while (n > 1) {
			ans *= n;
			n--;
		}
		return ans;
	}

	lint mod0(lint n, lint mod)
	{
		lint tmp = n % mod;
		if (tmp == 0)
			return mod;
		return tmp;
	}

	char caesar(char s, lint key)
	{
		if (between(s, 'A', 'Z'))
		{
			return (s - 'A' + key) % alpn + 'A';
		}
		if (between(s, 'a', 'z'))
		{
			return (s - 'a' + key) % alpn + 'a';
		}
		return s;
	}

	string caesar(string s, lint key)
	{
		rep(i, s.length())
			s[i] = caesar(s[i], key);
		return s;
	}

#define ret return 0;

	template<class It>
	auto spacel(It i, It end)
	{
		if (i + 1 == end)
		{
			return '\n';
		}
		else
		{
			return ' ';
		}
	}

	template<bool f>
	auto make_ptbl(lint n) {
		vec_(a, n + 1, 0);
		vec(p, 0);

		repb(i, 2, n) {
			if (a[i] == 1)
			{
				continue;
			}
			p.push_back(i);
			for (lint j = i * 2; j <= n; j += i)
			{
				a[j] = 1;
			}
		}
		if (f)
		{
			return a;
		}
		else
		{
			return p;
		}
	}

	template<class It>
	bool next_comb(lint n, It begin, It end)
	{
		auto rend = make_reverse_iterator(begin);
		auto rbegin = make_reverse_iterator(end);

		auto rit = rbegin;
		for (; rit != rend; rit++)
		{
			if ((rit == rbegin && (*rit) + 1 != n) ||
				(rit != rbegin && (*rit) + 1 != *(rit - 1)))
			{
				goto found;
			}
		}
		return false;
	found:;
		(*rit)++;

		for (auto it = rit.base(); it != end; it++)
		{
			(*it) = (*(it - 1)) + 1;
		}
		return true;
	}

	template<class T, class Pred>
	pair<T, T> bin(T begin, T end, Pred p)
	{
		while (end - begin > 1)
		{
			T tgt = begin + (end - begin) / 2;

			if (p(tgt))
			{
				begin = tgt;
			}
			else
			{
				end = tgt;
			}
		}

		return make_pair(begin, end);
	}

	template<class It, class Pred>
	pair<It, It> bin_p(It begin, It end, Pred p)
	{
		return bin(begin, end, [&](It it) {

			return p(*it);

			});
	}

	const auto setp = setprecision(60);

	class graph
	{
		struct R
		{
			lint to, c;
		};

		lint v, e;

		vector<vector<R>> gr;
	public:
		graph(lint _v) : v(_v), e(0), gr(v)
		{}

		void add_e(lint from, lint to, lint cost)
		{
			gr[from].push_back({ to, cost });
			e++;
		}

		auto dijkstra(lint start)
		{
			vector<lint> d(v, intmax);
			vector<bool> finish(v, false);
			lint finishn = 0;

			d[start] = 0;

			struct Vc
			{
				lint pos, d;
				bool operator<(const Vc& p) const
				{
					return d > p.d;
				}
			};

			priority_queue<Vc> que;
			que.push({ start, 0 });

			while (finishn < v && !que.empty())
			{
				auto vc = que.top();
				que.pop();
				if (!finish[vc.pos])
					finishn++;
				finish[vc.pos] = true;

				rep(i, gr[vc.pos].size())
				{
					if (finish[gr[vc.pos][i].to])
						continue;

					if (vc.d + gr[vc.pos][i].c < d[gr[vc.pos][i].to])
					{
						d[gr[vc.pos][i].to] = vc.d + gr[vc.pos][i].c;
						que.push({ gr[vc.pos][i].to, d[gr[vc.pos][i].to] });
					}
				}
			}

			return d;
		}
		
	};

#ifdef ATCODER_LOCAL
	auto& dbg = cout;
#else
	struct dummy_cout
	{
		template<class T>
		dummy_cout& operator<<(T&& op)
		{
			return *this;
		}

		using endl_t = basic_ostream<char, char_traits<char>>;

		dummy_cout& operator<<(endl_t& (*)(endl_t&))
		{
			return *this;
		}
	};

	dummy_cout dbg;
#endif
}

int main()
{
	lint v, e, r;
	cin >> v >> e >> r;
	graph gr(v);
	rep(i, e)
	{
		lint s, t, c;
		cin >> s >> t >> c;
		gr.add_e(s, t, c);
	}

	auto d = gr.dijkstra(r);
	rep(i, v)
		cout << (d[i] == intmax ? "INF"s : to_string(d[i])) << endl;

	return 0;
}

