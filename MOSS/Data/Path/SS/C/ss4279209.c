#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
constexpr ll MOD = (1e9 + 7);
//constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

//template<class T>vector<T> vec(size_t a) { return vector<T>(a); }

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

ll maxVec(vector<ll> &v) {
	ll ans = -INF;
	rep(i, v.size()) {
		ans = max(ans, v[i]);
	}
	return ans;
}


int main() {
	
	auto comp =  [](const pll a, const pll b) { return a.first > b.first; };
	priority_queue<pll, vector<pll>, decltype(comp)> que(comp);

	ll v, e, r,s,t,d;
	pll a;
	cin >> v >> e >> r;
	vector<vector<pll>> graph(v, vector<pll>(0));
	rep(i, e) {
		cin >> s >> t >> d;
		graph[s].push_back(pll{t,d});
	}
	que.push(pll{ 0, r });

	vl ans(v, INF);
	ans[r] = 0;

	while (!que.empty()) {
		ll c = que.top().first, p = que.top().second;
		que.pop();
		rep(i, graph[p].size()) {
			a = graph[p][i];
			if (ans[a.first] > a.second + c) {
				ans[a.first] = a.second + c;
				que.push(pll{ a.second + c,a.first });
			}
		}
	}
	rep(i, v) {
		if (ans[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << ans[i] << endl;
		}
	}
}
