#include <bits/stdc++.h>
using namespace std;

/***** type *****/
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
template <class T> using uset = unordered_set<T>;
template <class T1, class T2> using umap = unordered_map<T1, T2>;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
#define val(itr) *(itr)                          // get value
#define pair NyaaPair                            // nyaa pair
#define first f                                  // pair::first
#define second s                                 // pair::second
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define pi 3.1415926535897932                    // 3.14 ...
#define loop_end 9223372036854775806             // LLONG_MAX-1
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, c) fori(i, auto e = c.begin(); e != c.end(); ++e)
#define forir(i, v, ...) if(ll i=(ll)v.size())for(__VA_ARGS__)if(i--,true)
#define eachr(i, e, c) forir(i, auto e = c.rbegin(); e != c.rend(); ++e)

/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it)*it += fix; };
auto Pow = [] // long long pow
(auto a, auto b) { return (ll)pow(a, b); };
auto Pow2 = [] // long long pow2
(auto n) { return (1LL << n); };
auto Pow10 = [] // long long pow10
(auto n) { return (ll)pow(10, n); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = [] // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };

/***** template *****/
template <class T> void MakeVVT
(ll ys, ll xs, vvt<T>& v, T fill = T())
{	// vector<vector<T>> resize + fill
	v.resize(ys); rep(y, 0, ys) v[y].resize(xs, fill);
}
template <class T> void MakeVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	v.resize(zs); rep(z, 0, zs) MakeVVT(ys, xs, v[z], fill);
}
template <class T> void InputVT
(ll xs, vt<T>& v, T fix = T())
{	// input vector<T> (T != struct) + fix
	v.resize(xs); rep(i, 0, xs) { cin >> v[i]; v[i] += fix; }
}
template <class T> void InputVVT
(ll ys, ll xs, vvt<T>& v, T fix = T())
{	// input vector<vector<T>> (T != struct) + fix
	MakeVVT(ys, xs, v, fix);
	rep(y, 0, ys) rep(x, 0, xs) { cin >> v[y][x]; v[y][x] += fix; }
}
template <class T> void InputVVVT
(ll zs, ll ys, ll xs, vvvt<T>& v, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	v.resize(zs); rep(z, 0, zs) InputVVT(ys, xs, v[z], fix);
}

/***** nyaa pair template *****/
template <class T1, class T2> struct NyaaPair
{ T1 f; T2 s; };
template <class T1, class T2> bool operator < 
(const NyaaPair<T1, T2>& l, const NyaaPair<T1, T2>& r)
{ return (l.f != r.f) ? l.f < r.f : l.s < r.s; }

/**************************************/
/********** BEGIN OF NYA LIB **********/
/**************************************/

namespace NyaGadget {}

namespace NyaGadget
{
	/*** ダイクストラ法ライブラリ ***/

	/**
	@brief ダイクストラ法で処理する関数
	@param n 頂点数
	@param s スタート地点
	@param G 重みつき隣接行列
	@param res 結果を格納する構造体
	@note
	 計算量O((V+E)log(V))
	 G[a][i]=(b,c)は頂点aの辺i(a->b)のコストがcを表す
	**/
	void GT_Dijkstra
	(long long n, long long s, vector<vector<pair<long long, long long>>>& G, vector<long long>& res)
	{
		long long MAX = n;
		long long INF = LLONG_MAX;
		int WHITE = 0; // 最短距離が確定してない
		int GRAY = 1;  // 最短距離が更新されたことを表す(処理には無関係)
		int BLACK = 2; // 最短距離確定

		vector<long long> d(MAX), color(MAX);
		priority_queue<pair<long long, long long>> PQ;
		for (long long i = 0; i < n; i++)
		{
			d[i] = INF;
			color[i] = WHITE;
		}

		d[s] = 0;
		color[s] = GRAY;
		PQ.push({ 0, s });
		while (!PQ.empty())
		{
			pair<long long, long long> f = PQ.top(); PQ.pop();
			long long u = f.second;
			color[u] = BLACK;
			if (d[u] < f.first * (-1)) continue;

			for (long long j = 0; j < (long long)G[u].size(); j++)
			{
				long long v = G[u][j].first;
				if (color[v] == BLACK) continue;
				if (d[v] > d[u] + G[u][j].second)
				{
					d[v] = d[u] + G[u][j].second;
					// 逆順で並べるため-1倍する
					PQ.push({ d[v] * (-1), v });
					color[v] = GRAY;
				}
			}
		}
		res.resize((long long)d.size());
		for (long long i = 0; i < (long long)d.size(); i++)
			res[i] = (d[i] != INF) ? d[i] : -1;
	}
}

/**************************************/
/*********** END OF NYA LIB ***********/
/**************************************/

using namespace NyaGadget;
//using mll = ModLL< 1000000007 >;

int main(void)
{
	ll v, e, r; cin >> v >> e >> r;

	vvt<pair<ll, ll>> G(v);
	rep(i, 0, e)
	{
		ll s, t, d; cin >> s >> t >> d;
		G[s].push_back({ t, d });
	}

	vt<ll> res;
	GT_Dijkstra(v, r, G, res);
	each(i, e, res)
	{
		if (val(e) == -1) cout << "INF" << endl;
		else cout << val(e) << endl;
	}
	return 0;
}

