#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin() , v.end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, w, l, ans = 0;
struct edge {
	ll to, cost;
};
struct Gragh {
	vector<vector<edge>> G;
	ll N;
	vl visited;
	void init(ll n) {
		N = n;
		G.resize(N);
		visited = vl(N, 0);
	}

	void add(ll a, ll b, ll c = 1) {
		G[a].push_back((edge){b,c});
	}

	void resetv(void) {
		visited = vl(N, 0);
	}

	vl Dijkstra(ll r) {
		vl cost(N,INF);
		resetv();
		priority_queue<PP, vector<PP>, greater<PP>> pq;
		ll a, b = r;
		cost[b] = 0;
		visited[b] = 1;

		for (edge i : G[b]) {
			if (cost[b] + i.cost < cost[i.to]) {
				pq.push(make_pair(cost[b] + i.cost, i.to));
			}
		}
		while (!pq.empty()) {
			a = pq.top().first;
			b = pq.top().second;
			pq.pop();
			if (visited[b] == 1)continue;
			visited[b] = 1;
			cost[b] = a;
			for (edge i : G[b]) {
				if (cost[b] + i.cost < cost[i.to]) {
					pq.push(make_pair(cost[b] + i.cost, i.to));
				}
			}
		}

		return cost;
	}
};

int main() {
	cin >> n >> m >> x;
	Gragh g;
	g.init(n);
	rep(i, m) {
		cin >> a >> b >> c;
		g.add(a, b, c);
	}

	vl A = g.Dijkstra(x);

	rep(i, n) {
		if (A[i] < INF) {
			cout << A[i] << endl;
		}
		else {
			cout << "INF" << endl;
		}
	}
}
