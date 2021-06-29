#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;
int n, m, r, t1, t2, t3, d[100005];
pii p1;
vector <pii> v[100005];
priority_queue <pii, vector <pii>, greater <pii>> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) d[i] = INF;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		v[t1].pb(mp(t2, t3));
//		v[t2].pb(mp(t1, t3));
	}
	d[r] = 0;
	q.push(mp(0, r));
	while (!q.empty()) {
		p1 = q.top(); q.pop();
		int &w = p1.fi, &u = p1.se;
		if (d[u] != w) continue;
		for (pii i : v[u]) {
			if (w + i.se < d[i.fi]) {
				d[i.fi] = w + i.se;
				q.push(mp(d[i.fi], i.fi));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}
}

