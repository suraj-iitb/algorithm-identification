//↓template↓

#include "bits/stdc++.h"
using namespace std;
#define Would
#define you
#define all(n)  n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double pi = acos(-1);
const ll SIZE = 1 << 17;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, alp[30];
ll fac[200005], finv[200005], inv[200005];
vector<ll>dij;
struct edge { ll to, cost; };
vector<vector<edge> >G;

ll mod_pow(ll a, ll b) {
	ll res = 1, mul = a;
	for (int i = 0; i < 31; ++i) {
		if (b >> i & 1) {
			res *= mul;
			res %= MOD;
		}
		mul = (mul * mul) % MOD;
	}
	return res;
}

void addedge(int from, int to, int cost) {
	G[from].push_back({ to,cost });
	G[to].push_back({ from,cost });
}


template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) {
	for (auto &e : t) fill_v(e, v);
}

template<typename T>
void outp(vector<T>v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1) { cout << " "; }
	}
}

//↑template↑




void dijkstra(int n) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>que;
	fill(dij.begin(), dij.end(), INF);
	dij[n] = 0;
	que.push(pair<ll, ll>(0, n));

	while (!que.empty()) {
		pair<ll, ll>p = que.top();
		que.pop();
		ll mon = p.second;
		if (dij[mon] < p.first) continue;
		for (int i = 0; i < G[mon].size(); ++i) {
			edge e = G[mon][i];
			if (dij[e.to] > dij[mon] + e.cost) {
				dij[e.to] = dij[mon] + e.cost;
				que.push(pair<ll, ll>(dij[e.to], e.to));
			}
		}
	}
}


int main() {
	int a, b, c;
	cin >> a >> b >> c;
	G.resize(a + 1);
	dij.resize(a + 1);
	for (int i = 0; i < b; ++i) {
		int n, m, mm;
		cin >> n >> m >> mm;
		G[n].push_back({ m,mm });
	}

	dijkstra(c);
	for (int i = 0; i < a; ++i) {
		if (dij[i] != INF) { cout << dij[i] << endl; }
		else { cout << "INF" << endl; }
	}
}
