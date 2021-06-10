#include <vector> 
#include <list> 
#include <map>
#include <set>//2分探索木
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>// キュー　優先度付きキュー
#include <stack>
#include <complex>
#include <memory>
#include <assert.h>
#ifdef LOCAL
#include "UnionFind.h"//同じグループに属するか
#include "Prime.h"//素数判定
#include "RMQ.h"//区間最小値
#include "BIT.h"//累積和
#include "Dijkstra.h"//単一始点最短経路(負の辺があるときは動作しない)　O(ElogV)
#endif

using namespace std;

//conversion
//------------------------------------------
inline long long toInt(string s) { long long v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<PII> VPII;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(t,c) for(typeof((c).begin()) t=(c).begin(); t!=(c).end(); ++t)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(t,a,b) for(int t=(a);t<(b);++t)
#define REP(t,n)  FOR(t,0,n)

//constant
//------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

//clear memory
//------------------------------------------
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
//------------------------------------------
#if defined(__GNUC__) 
#include <assert.h>
#define ASSERT_(x) assert(x)
#else
#include <assert.h>
#define ASSERT_(x) assert(x)
#endif
#ifdef _DEBUG
#define dump(x)  cerr << #x << '=' << (x) << endl;
#define debug(x) cerr << #x << '=' << (x) << '('<<'L' << __LINE__ << ')' << ' ' << __FILE__ << endl;
#define ASSERT(x) {if (!(x)){std::cerr << "\nError!!\n" << "info string file:" << __FILE__ << " line:" << __LINE__ <<" "<< #x<< std::endl;ASSERT_(x);}}
#else
#define ASSERT(x) ((void)0)
#define debug(x) ((void)0)
#define dump(x)  ((void)0)
#endif // _DEBUG
template<class T> void showVector(vector<T>& v) {
	for (int i = 0; i < v.size(); ++i)
		cerr << v[i] << " ";
	cerr << endl;
}


//mod
//-------------------------------------------
const LL mod = 1000000007;
LL mod_pow(LL x, LL n, LL mod) {
	if (n == 0) { return 1; }
	LL res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) { res = res * x % mod; }
	return res;
}

//bitop
//-------------------------------------------
#if defined(__GNUC__)
#include <immintrin.h>
int popcount(int a) {
	return __builtin_popcount(a);
}
#elif defined(_MSC_VER)
#include <intrin.h>
int popcount(int a) {
	return __popcnt(a);
}
#endif 

//gcd lcm
//-------------------------------------------
LL gcd(LL a, LL b) { if (a%b == 0) { return b; } else return gcd(b, a%b); }
LL lcm(LL a, LL b) { return a / gcd(a, b)*b; }


//YES_NO
//------------------------------------------
#define Yes_ cout<<"Yes"<<endl; return 0;
#define No_ cout<<"No"<<endl; return 0;

#define YES_ cout<<"YES"<<endl; return 0;
#define NO_ cout<<"NO"<<endl; return 0;

#define POSSIBLE cout<<"POSSIBLE"<<endl; return 0;
#define IMPOSSIBLE cout<<"IMPOSSIBLE"<<endl; return 0;

//matrix
//------------------------------------------
template <class T> class matrix : public vector< vector<T> > {
private:
	int tate_, yoko_;
public:
	matrix(const int tate__, const int yoko__) {
		ASSERT(tate__ > 0); ASSERT(yoko__ > 0);
		this->resize(tate__);
		for (size_t i = 0; i < this->size(); i++) { (*this)[i].resize(yoko__); }
		tate_ = tate__; yoko_ = yoko__;
	}
	matrix() {};
	int tate()const { return tate_; }
	int yoko()const { return yoko_; }
	void resizematrix(const int tate__, const int yoko__) {
		ASSERT(tate__ > 0); ASSERT(yoko__ > 0);
		this->resize(tate__);
		for (size_t i = 0; i < this->size(); i++) {
			(*this)[i].resize(yoko__);
		}
		tate_ = tate__; yoko_ = yoko__;
	}
	void setone() {for (int i = 0; i < tate(); i++)  for (int j = 0; j < yoko(); j++) { (*this)[i][j] = 1; }}
	void setzero() {for (int i = 0; i < tate(); i++) for (int j = 0; j < yoko(); j++) { (*this)[i][j] = 0; }}
	void setAll(T a) {for (int i = 0; i < tate(); i++) for (int j = 0; j < yoko(); j++) { (*this)[i][j] = a; }}
};
template<class T> std::ostream& operator<<(std::ostream& os, const matrix<T>& m)
{
	for (int j = 0; j < m.tate(); j++) {
		for (int i = 0; i < m.yoko(); i++) {
			os << (int)m[j][i];
		}
		os << endl;
	}
	return os;
}

//time
//------------------------------------------
#if defined(__GNUC__) 
#include <sys/time.h>
#include <immintrin.h>
#include <string.h>
LL starttime;
inline LL now() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	LL t = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
	return t;
}
inline LL elapsed() { return now() - starttime; }
#else
#include <chrono>
#include <intrin.h>
typedef std::chrono::milliseconds::rep TimePoint;
inline TimePoint now() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count(); }
TimePoint starttime;
inline TimePoint elapsed() { return now() - starttime; }
#endif


//=====================================================
struct Dijkstra {
	struct Edge
	{
		int cost,to;
	};
	const int INF = 1e+9;
	std::vector<std::vector<Edge>> edges;
	std::vector<int> ds;
	Dijkstra() {};
	Dijkstra(int V_) :edges(V_), ds(V_) {  };

	void make_mincosts(int s) {
		for (int i = 0; i < ds.size(); i++) { ds[i] = Dijkstra::INF; }
		ds[s] = 0;
		//PII first:cost second:to
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;

		que.push({ 0,s });
		while (que.size() != 0) {
			std::pair<int, int> p = que.top(); que.pop();
			int v = p.second;
			if (ds[v] < p.first) { continue; }
			for (int i = 0; i < edges[v].size(); i ++) {
				const Edge& e = edges[v][i];
				if (ds[e.to] > ds[v] + e.cost) {
					ds[e.to] = ds[v] + e.cost;
					que.push({ ds[e.to],e.to });
				}
			}

		}
	}

	void addedge(int from,int to,int cost) {
		edges[from].push_back(Dijkstra::Edge{ cost,to });
	}
};


int main() {
	int V, E,r;
	cin >> V >> E >> r;
	Dijkstra dks(V);
	REP(i, E) {
		int a, b, c;
		cin >> a >> b >> c;
		dks.addedge(a, b, c);
	}
	dks.make_mincosts(r);
	REP(i, SZ(dks.ds)) {
		cout << ((dks.ds[i] == 1e+9) ? "INF" : toString(dks.ds[i])) << endl;
	}
}
