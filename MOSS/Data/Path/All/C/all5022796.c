#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector< vector<ll> > Graph;
struct Edge { int to; int weight; Edge(int t, int w) : to(t), weight(w) {} };
typedef vector< vector<Edge> > GraphW;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#define ALL(v) (v).begin(), (v).end()
#define FIND(v, x) find(v.begin(), v.end(), (x))
#define HASELM(v, x) find(v.begin(), v.end(), (x)) != v.end()
#define INDEX(v, x) distance(v.begin(), find(v.begin(), v.end(), (x)))
#define rep(i, N) for (ll i = 0; i < N; i++)
#define repr(i, from, to) for (ll i = from; i < to; i++)
#define PER(i, N) for (ll i = N - 1; i >= 0; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v, n) reverse(v, v + n);
#define VREVERSE(v) reverse(v.begin(), v.end())

#define print(x) cout << (x) << '\n'
#define say_yes() cout << "Yes" << '\n'
#define say_no() cout << "No" << '\n'

const int MOD = 1000000007;
const ld PI = 3.1415926535897932;

vector<ll> divisor(ll n) { vector<ll> ret; for (ll i = 1; i * i <= n; i++) { if (n % i == 0) { ret.push_back(i); if (i * i != n) ret.push_back(n / i); }  } sort(ret.begin(), ret.end()); return ret; }
ll gcd(ll a, ll b) { while (b) { ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b) { if (!a || !b) return 0; return a * b / gcd(a, b); }
ll nck(ll n, ll k) { ll num = 1; for(ll i = 1; i <= k; i++) { num = num * (n - i + 1) / i; } return num; }
ll intpow(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p) { ll ans = 1; while (b) { if (b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T, class U> bool chmin(T& a, const U& b) { if (a > b) { a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b) { if (a < b) { a = b; return 1; } return 0; }
template<typename TypeInt> string toBaseNum(const TypeInt v, int base) {
    static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ret;	static numeric_limits<TypeInt> t; TypeInt n = v;
	if (t.is_signed) { if (v < 0) n *= -1; }
	while (n >= base) { ret += table[n%base]; n /= base; }
	ret += table[n];
	if (t.is_signed) { if (v < 0 && base == 10) ret += '-'; }
	std::reverse(ret.begin(), ret.end()); return ret;
}

static const ll MAXV = 100;
static const ll INF = 1LL << 60;

// V: 頂点数，E: 辺の数
// d[u][v]は辺 (u,v) のコスト
// 存在しない場合：INF，d[i][i]=0
ll V, E, d[MAXV][MAXV];

void warshall_floyd() {
	rep(k, V) rep(i, V) rep(j, V) {
		// i: 始点，j: 終点
		// k: 0 ~ k-1 の頂点まで使うときのi->jへの最短路がd[i][j]
		// i->jへの最短経路は以下2つの経路の最小値
		//   1. kを通らない: d[i][j]のまま更新なし
		//   2. kを通る: cost(i->k) + cost(k->j) = d[i][k] + d[k][j]
		//   i->k, k->jへの経路が無い場合には上記1のケース
		if (d[i][k] == INF || d[k][j] == INF) continue;
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

	cin >> V >> E;

	// 初期化．d[i][i] = 0．それ以外はINF．
	rep(i, V) rep(j, V) d[i][j] = (i == j) ? 0 : INF;

	// d[i][j]を(i,j)の辺の長さddで初期化するためグラフの構造体Gは不要
	rep(i, E) {
		ll s, t, dd; cin >> s >> t >> dd;
		d[s][t] = dd;
	}

	warshall_floyd();

	// 負の閉路 (辺の重みの和が負になるような閉路) があるか調べる
	rep(i, V) {
		if (d[i][i] < 0) {
			print("NEGATIVE CYCLE");
			return 0;
		}
	}

	// 負の閉路がない場合には各2頂点間の最短経路を出力
	rep(i, V) {
		rep(j, V) {
			if (j) cout << " ";
			if (d[i][j] == INF) cout << "INF";
			else cout << d[i][j];
		}
		cout << endl;
	}
}

