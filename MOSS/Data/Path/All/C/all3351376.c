
//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <limits>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
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

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define EXISTch(s,c) ((((s).find_first_of(c)) != std::string::npos)? 1 : 0)//cがあれば1 if(1)
#define SORT(c) sort((c).begin(),(c).end())

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);
const int INF = (int)1000000007;
const LL MOD = (LL)1000000007;//10^9+7
const LL INF2 = (LL)100000000000000000;//10^18

template< typename T >
struct edge {
	int src, to;
	T cost;

	edge(int to, T cost) : src(-1), to(to), cost(cost) {}

	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

	edge &operator=(const int &x) {
		to = x;
		return *this;
	}

	operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
void warshall_floyd(Matrix< T > &g, T INF) {
	for (int k = 0; k < g.size(); k++) {
		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < g.size(); j++) {
				//負の辺+INFをしてしまうとバグるので
				if (g[i][k] == INF || g[k][j] == INF) continue;
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}

int main() {
	int V, E;
	cin >> V >> E;
	Matrix< int > mat(V, vector< int >(V, INT_MAX));
	for (int i = 0; i < V; i++) mat[i][i] = 0;
	for (int i = 0; i < E; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		mat[x][y] = z;
	}
	warshall_floyd(mat, INT_MAX);
	for (int i = 0; i < V; i++) {
		if (mat[i][i] < 0) {
			puts("NEGATIVE CYCLE");
			return 0;
		}
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (j > 0) putchar(' ');
			if (mat[i][j] == INT_MAX) printf("INF");
			else printf("%d", mat[i][j]);
		}
		putchar('\n');
	}
}
