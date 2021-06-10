//ほとんどbetrue12さんの提出(https://atcoder.jp/contests/abc168/submissions/13352386)の写経です

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
//#pragma warning(disable : 4996)

#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#define __builtin_popcountll __popcnt64
#endif

#include <limits.h>
#include <math.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m - 1; i >= n; --i)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v, n) reverse(v, v + n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout << (x) << '\n'
#define pe(x) cout << (x) << " "
#define DEBUG(x) cout << #x << ": " << x << endl
#define lb(v, n) lower_bound(v.begin(), v.end(), (n))
#define ub(v, n) upper_bound(v.begin(), v.end(), (n))
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i, v.size()) cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template <typename T1, typename T2> inline void chmin(T1& a, T2 b) {
	if (a > b) a = b;
}
template <typename T1, typename T2> inline void chmax(T1& a, T2 b) {
	if (a < b) a = b;
}
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 998244353;
constexpr int MAX = 500050;
const double pi = acos(-1);
constexpr double EPS = 1e-8;
constexpr ll LINF = 1e18 + 1;
constexpr int INF = 1e18 + 1;

using P = pair<int, int>;

struct edge { int to, cost; };
int V;//頂点数
vector<edge>G[MAX];
int d[MAX];//始点からの距離
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>>que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

void solve() {
	int N, M, S; cin >> N >> M >> S;
	V = N;
	REP(i, M) {
		int u, v; cin >> u >> v;
		int d; cin >> d;
		G[u].push_back({ v,d });

	}
	dijkstra(S);
	REP(i, N) {
		if (d[i] == INF)print("INF");
		else print(d[i]);
	}
}



signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//mt.seed((int)(time(0)));
	//REP(_, 10000)test();
	//int q;
	//cin >> q;
	//while (q--)
	solve();
}


