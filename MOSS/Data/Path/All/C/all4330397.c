#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep0(n) for (int counter = 0; counter < (int)(n); counter++)
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

const int INF = 2e9 + 7;
int V, E;
vvi dp2; // dp[i][j]: iからjへ移動する際の最小コスト(0~k-1の頂点(のみ)を経由して)
// dp[i][j]のk=0での初期値はi→jのコストを入れる(辺が無ければINF)

int main() {
	cin >> V >> E;
	dp2.assign(V, {}); rep(i, V) dp2[i].assign(V, INF);
	rep(i, V) dp2[i][i] = 0;
	rep0(E) {
		int s, t; cin >> s >> t;
		cin >> dp2[s][t];
	}
	// dbvv(dp2);
	rep(k, V) {
		rep(i, V) {
			rep(j, V) {
				if (dp2[i][k] != INF and dp2[k][j] != INF) {
					dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);
				}
				// db3l(k, i, j); dbvv(dp2);
			}
		}
		// dbl(k); dbvv(dp2);
	}
	// dp[i][i] < 0 なるiが存在すればコスト負の閉路を含む
	bool f = false;
	rep(i, V) if(dp2[i][i] < 0) f = true;
	if (f) {
		cout << "NEGATIVE CYCLE" << endl;
	} else {
		rep(i, V) {			
			rep(j, V) {
				if (j) cout << " ";
				if (dp2[i][j] == INF) cout << "INF";
				else cout << dp2[i][j];
			}
			cout << endl;
		}
	}
}
