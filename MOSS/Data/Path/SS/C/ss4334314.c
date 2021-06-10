#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep0(n) for (int i = 0; i < (int)(n); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define rep3(i, s, n) for (int i = s; i > (int)(n); i--)
#define ALL(obj) obj.begin(), obj.end()
#define from1(obj) obj.begin() + 1, obj.end()
#define db(x) cerr << #x << ":" << (x) << " "
#define dbl(x) cerr << #x << ":" << (x) << "\n"
#define db2(x, y) cerr << #x << ":" << (x) << ", " << #y << ":" << (y) << " "
#define db2l(x, y) cerr << #x << ":" << (x) << ", " << #y << ":" << (y) << "\n"
#define dbl2(x, y) cerr << #x << ":" << (x) << "\n" << #y << ":" << (y) << "\n"
#define db3(x, y, z) cerr << #x << ":" << (x) << ", " << #y << ":" << (y) << " " << #z << ":" << (z) << " "
#define db3l(x, y, z) cerr << #x << ":" << (x) << ", " << #y << ":" << (y) << ", " << #z << ":" << (z) << "\n"
#define dbl3(x, y, z) cerr << #x << ":" << (x) << "\n" << #y << ":" << (y) << "\n" << #z << ":" << (z) << "\n"
#define dbp(p) cerr << #p << ":(" << p.first << ", " << p.second << ") "
#define dbpl(p) cerr << #p << ":(" << p.first << ", " << p.second << ")\n"
#define dbt3(t3) cerr << #t3 << ":(" << get<0>(t3) << ", " << get<1>(t3) << ", " << get<2>(t3) << ") "
#define dbt3l(t3) cerr << #t3 << ":(" << get<0>(t3) << ", " << get<1>(t3) << ", " << get<2>(t3) << ")\n"
#define dbt4(t4) cerr << #t4 << ":(" << get<0>(t4) << ", " << get<1>(t4) << ", " << get<2>(t4) << ", " << get<3>(t4) << ") "
#define dbt4l(t4) cerr << #t4 << ":(" << get<0>(t4) << ", " << get<1>(t4) << ", " << get<2>(t4) << ", " << get<3>(t4) << ")\n"
#define dbv(vec) cerr << #vec << ":{ "; for (auto e : vec) cerr << e << ", "; cerr << "}\n"
#define dbvp(vec) cerr << #vec << ":{ "; for (auto p : vec) cerr << "(" << p.first << ", " << p.second << "), "; cerr << "}\n"
#define dbvv(vv) cerr << #vv << ":{\n"; for (auto vec : vv) { cerr << "{ "; for (auto e : vec) cerr << e << ", "; cerr << "}\n"; } cerr << "}\n"
#define dbm(map) cerr << #map << ":{ "; for (auto p : map) cerr << "(" << p.first << ", " << p.second << "), "; cerr << "}\n"
#define YN(f) cout << (f ? "YES" : "NO") << "\n"
#define Yn(f) cout << (f ? "Yes" : "No") << "\n"
#define yn(f) cout << (f ? "yes" : "no") << "\n"
using ll = long long;
using vi = vector<int>; using vl = vector<ll>; using vs = vector<string>; using vb = vector<bool>;
using vvi = vector<vi>; using vvl = vector<vl>; using vvb = vector<vb>;
using pii = pair<int, int>; using pil = pair<int, ll> ; using pli = pair<ll, int>; using pll = pair<ll, ll>;
using vpii = vector<pii>; using vpll = vector<pll>;
using ti3 = tuple<int, int, int>; using tl3 = tuple<ll, ll, ll>;
using ti4 = tuple<int, int, int, int>; using tl4 = tuple<ll, ll, ll, ll>;
using mii = map<int, int>; using mil = map<int, ll>; using mli = map<ll, int>; using mll = map<ll, ll>;

int main() {
	const int INF = 1e9 + 7;
	int V, E; cin >> V >> E;
	int r; cin >> r;	
	vector<vpii> g(V); // adjcostlist g[u]={(v,cost(u,v))}
	rep0(E) {
		int s, t, d; cin >> s >> t >> d;
		g[s].push_back(pii(t, d));
	}
	// rep(i, V) { dbvp(g[i]); }
	vi dp(V, INF); // 始点からのコストの最小値
	queue<int> q; // vのみを入れる(FIFOなのでこれでよい)
	q.push(r); dp[r] = 0; // 始点
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (pii p : g[u]) {
			int v, d; tie(v, d) = p; // d=cost(u,v)
			if (dp[u] + d < dp[v]) { // FIFOなので今回uにたどり着いた時のuまでのコストとしてdp[u]を使用してよい。
				dp[v] = dp[u] + d;
				q.push(v);
			}
		}				
	}
	// dbv(dp);
	rep(i, V) {
		if (dp[i] != INF) cout << dp[i] << endl;
		else cout << "INF" << endl;
	}
}
