#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#define int long long
#define endre getchar();getchar();return 0
#define moder 1000000007
#define inf 1000000000000000000
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

bool prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int mod_pow(int x, int y, int mod) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x%mod;
		}
		x = x * x%mod;
		y >>= 1;
	}
	return res;
}
int kai(int x) {
	if (x == 0)return 1;
	return (kai(x - 1)*x) % moder;
}

int comb(int x, int y) {
	return kai(x)*mod_pow(kai(x - y), moder - 2, moder) % moder*mod_pow(kai(y), moder - 2, moder) % moder;
}
struct edge { int to, cost; };
int dx[5] = { 0,1,0,-1 }, dy[5] = { 1,0,-1,0 };
/*--------Library Zone!--------*/

class dijkstra {
public:
	int V;
	dijkstra(int x) {
		V = x;
	}
	int far[100005];
	vector<edge>G[100005];
	void solve(int st) {
		fill(far, far + V, moder);
		far[st] = 0;
		prique(P)que;
		que.push({ 0,st });
		while (que.size()) {
			P p = que.top(); que.pop();
			int v = p.second;
			if (far[v] < p.first)continue;
			rep(i, G[v].size()) {
				edge e = G[v][i];
				if (far[e.to] > far[v] + e.cost) {
					far[e.to] = far[v] + e.cost;
					que.push({ far[e.to],e.to });
				}
			}
		}
	}
};
signed main() {
	int n, m, s;
	cin >> n >> m >> s;
	static dijkstra dijk(n);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		dijk.G[a].push_back({ b,c });
	}
	dijk.solve(s);
	rep(i, n) {
		if (dijk.far[i] != moder)cout << dijk.far[i] << endl;
		else cout << "INF" << endl;
	}
	endre;
}

