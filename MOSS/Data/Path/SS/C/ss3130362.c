#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <bitset>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <deque>
using namespace std;
#define INF 10000000
#define LLINF 100000000000000
typedef pair<long long, long long> P;
typedef long long ll;
#define pb push_back
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define VSORT(v) sort(v.begin(), v.end());
#define fi first
#define se second
#define out(x) cout << x << endl;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0,1,0,-1 };
ll MOD = 1000000007;

struct edge {
	ll from, to, cost;
};

vector<P> es[500005];
int v, e, s;

void dijkstra() {
	ll d[100005] = { 0 };
	rep(i, v + 5) d[i] = LLINF;
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>>que;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		ll v = p.second;
		if (d[v] < p.first) continue;
		for (int u = 0; u < es[v].size(); u++) {
			ll to = es[v][u].first;
			ll cost = es[v][u].second;
			if (d[to] > d[v] + cost) {
				d[to] = d[v] + cost;
				que.push(P(d[to], to));
			}
		}
	}
	for (int i = 0; i < v; i++) {
		if (d[i] != LLINF) { out(d[i]); }
		else cout << "INF" << endl;
	}
	return;
}


int main() {
	cin >> v >> e >> s;
	for (int i = 0; i < e; i++) {
		ll s, t, d;
		cin >> s >> t >> d;
		es[s].pb(P(t, d));
	}
	dijkstra();
	return 0;
}
