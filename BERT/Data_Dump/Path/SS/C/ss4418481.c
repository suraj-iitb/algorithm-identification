#include<bits/stdc++.h>
#define int long long
#define mod 10000000070
#define for0(i, n) for(int i = 0; i < (n); i++)
#define mp make_pair
#define puts(x) cout << x << endl
using namespace std;
int v, e, r, ans[123456];
typedef pair<int, int> P;
vector<P>g[123456];
priority_queue<P, vector<P>, greater<P>>pq;
signed main() {
	cin >> v >> e >> r;
	for0(i, v)ans[i] = mod;
	while (e--) {
		int s, t, d; cin >> s >> t >> d;
		g[s].push_back(mp(t, d));
	}
	pq.push(mp(0, r));
	while (pq.size()) {
		P p1 = pq.top(); pq.pop();
		if (ans[p1.second] != mod)continue;
		ans[p1.second] = p1.first;
		for (P pv : g[p1.second]) {
			if (ans[pv.first] == mod)pq.push(mp(ans[p1.second] + pv.second, pv.first));
		}
	}
	for0(i, v)
		if (ans[i] == mod)puts("INF");
		else puts(ans[i]);
}
