////////////////////////////////////////
///  tu3 pro-con template            ///
////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;

//// MACRO ////

//// MACRO ////
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define RFOR(i,s,n) for (int i = (n)-1; i >= (s); i--)
#define allof(c) c.begin(), c.end()
#define partof(c,i,n) c.begin() + (i), c.begin() + (i) + (n)

typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;

#define EPS 1e-9
#define INF (1L << 28)
#define LINF (1LL << 60)
template <class T> T inf();
template <> constexpr int inf<int>() { return INF; }
template <> constexpr uint inf<uint>() { return INF; }
template <> constexpr llong inf<llong>() { return LINF; }
template <> constexpr ullong inf<ullong>() { return LINF; }
template <> constexpr double inf<double>() { return HUGE_VAL; }


#define PREDICATE(t,a,exp) [&](const t & a) -> bool { return exp; }
#define COMPARISON_T(t) bool(*)(const t &, const t &)
#define COMPARISON(t,a,b,exp) [&](const t & a, const t & b) -> bool { return exp; }
#define CONVERTER(TSrc,t,TDest,exp) [&](const TSrc &t)->TDest { return exp; }

#define PRED(a,exp) [&](const auto & a) -> bool { return exp; }
#define COMP(a,b,exp) [&](const auto & a, const auto & b) -> bool { return exp; }
#define CONV1(a,exp) [&](const auto & a) -> auto { return exp; }
#define CONV2(a,b,exp) [&](const auto & a, const auto & b) -> auto { return exp; }
#define CONV3(a,b,c,exp) [&](const auto & a, const auto & b, const auto & c) -> auto { return exp; }

inline int sign_of(double x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
inline bool inRange(int val, int min, int max) { return val >= min && val < max; }
inline bool inRange(double val, double min, double max) { return val - min > -EPS && val - max < EPS; }
inline bool inRange(int x, int y, int W, int H) { return x >= 0 && x < W && y >= 0 && y < H; } // W,H含まない

template <class T> struct vevector : public vector<vector<T>> { vevector(int n = 0, int m = 0, const T &initial = T()) : vector<vector<T>>(n, vector<T>(m, initial)) { } };
template <class T> struct vevevector : public vector<vevector<T>> { vevevector(int n = 0, int m = 0, int l = 0, const T &initial = T()) : vector<vevector<T>>(n, vevector<T>(m, l, initial)) { } };
template <class T> struct vevevevector : public vector<vevevector<T>> { vevevevector(int n = 0, int m = 0, int l = 0, int k = 0, const T &initial = T()) : vector<vevevector<T>>(n, vevevector<T>(m, l, k, initial)) { } };

//// i/o helper ////

namespace std {
	template <class T1, class T2> inline istream & operator >> (istream & in, pair<T1, T2> &p) { in >> p.first >> p.second; return in; }
	template <class T1, class T2> inline ostream & operator << (ostream &out, const pair<T1, T2> &p) { out << p.first << " " << p.second; return out; }
}
template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vector<T> readjag() { return read<T>(read<int>()); }
template <class T> vevector<T> readjag(int n) { vevector<T> v; REP(i, n) v.push_back(readjag<T>()); return v; }

template <class T> struct iter_pair_t { T beg, end; };
template <class T> iter_pair_t<T> iter_pair(T beg, T end) { return iter_pair_t<T>{beg, end}; }
template <class T> ostream & operator << (ostream &out, const iter_pair_t<T> &v)
{
	if (v.beg != v.end)
	{
		std::copy(v.beg, v.end - 1, ostream_iterator<typename decltype(v.beg)::reference>(out, " "));
		std::copy(v.end - 1, v.end, ostream_iterator<typename decltype(v.beg)::reference>(out));
	}
	return out;
}
template <class T1> ostream & operator << (ostream &out, const vector<T1> &v) { return out << iter_pair(begin(v), end(v)); }
template <class T1> ostream & operator << (ostream &out, const set<T1> &v) { return out << iter_pair(begin(v), end(v)); }
template <class T1, class T2> ostream & operator << (ostream &out, const map<T1, T2> &v) { return out << iter_pair(begin(v), end(v)); }

struct _Reader { istream &cin; template <class T> _Reader operator ,(T &rhs) { cin >> rhs; return *this; } };
struct _Writer { ostream &cout; bool f{ false }; template <class T> _Writer operator ,(const T &rhs) { cout << (f ? " " : "") << rhs; f = true; return *this; } };
#define READ(t,...) t __VA_ARGS__; (_Reader{cin}), __VA_ARGS__
#define WRITE(...) (_Writer{cout}), __VA_ARGS__; cout << '\n'
#define DEBUG(...) (_Writer{cerr}), __VA_ARGS__; cerr << '\n'

// iota vector 
vector<int> iotav(int begin, int end) { vector<int> r(end - begin);	iota(allof(r), begin);	return r; }

//// start up ////
void solve();
int main()
{
	//// for local debugging
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//auto classic_table = ctype<char>::classic_table();
	//vector<ctype<char>::mask> ctable(classic_table, classic_table + ctype<char>::table_size);
	//ctable[':'] |= ctype_base::space; // as delimitor
	//ctable[','] |= ctype_base::space; // as delimitor
	//cin.imbue(locale(cin.getloc(), new ctype<char>(ctable.data())));

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(std::numeric_limits<double>::max_digits10);
	solve();

	return 0;
}

// WarshallFloyd法 //
template <class TCost>
void WarshallFloyd(vevector<TCost> &cost)
{
	size_t n = cost.size();
	REP(k, n) REP(i, n) REP(j, n)
	{
		if (cost[i][k] != inf<TCost>() && cost[k][j] != inf<TCost>())
		{
			cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
		}
	}
}

////////////////////
/// template end ///
////////////////////

void solve()
{
	READ(int, V, E);
	vevector<llong> graph(V, V, inf<llong>());
	REP(i, V)
	{
		graph[i][i] = 0;
	}

	REP(i, E)
	{
		READ(int, s, t, d);
		graph[s][t] = d;
	}

	WarshallFloyd(graph);

	bool negativeCycle = false;
	REP(i, V) { negativeCycle |= graph[i][i] < 0; }

	if (negativeCycle)
	{
		WRITE("NEGATIVE CYCLE");
	}
	else
	{
		REP(i, V)
		{
			REP(j, V)
			{
				if (graph[i][j] < inf<llong>())
				{
					printf("%lld", graph[i][j]);
				}
				else
				{
					printf("INF");
				}
				if (j == V-1)
				{
					printf("\n");
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
}


