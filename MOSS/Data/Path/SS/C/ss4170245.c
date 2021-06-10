#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, char, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

const ll mod = 1000000007;

struct edge {
	ll to;
	ll cost;
};

int main(void)
{
	ll v, e, r;
	cin >> v >> e >> r;
	vector<vector<edge>> g(v);
	rep(i, e) {
		ll s, t, d;
		cin >> s >> t >> d;
		g[s].push_back({ t,d });
	}
	priority_queue<P, vector<P>, greater<P>> q;
	q.emplace(0, r);
	vector<bool> visit(v, false);
	vector<ll> distance(v, -1);
	while (!q.empty()) {
		auto p = q.top(); q.pop();
		auto d = p.first ;
		auto c = p.second;
		if (distance[c] >= 0) continue;
		distance[c] = d;
		for (auto element : g[c]) {
			auto to = element.to;
			if (distance[to] >= 0) continue;
			q.emplace(d + element.cost, to);
		}
	}
	rep(i, v) {
		if (distance[i] < 0) cout << "INF" << endl;
		else cout << distance[i] << endl;
	}
	return 0;
}

