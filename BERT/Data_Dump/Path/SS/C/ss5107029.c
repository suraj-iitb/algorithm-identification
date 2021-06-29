#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;
typedef long long ll;
constexpr ll inf = INT64_MAX / 4;

int main() {
	ll v, e, r, s, t, d, * x, * z;
	map<ll, map<ll, ll>> p;
	priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<>> q;
	cin >> v >> e >> r;
	for (ll i = 0; i < e; i++) {
		cin >> s >> t >> d;
		p[s][t] = d;
	}
	z = new ll[v];
	x = new ll[v];
	for (ll i = 0; i < v; i++) {
		z[i] = inf;
		x[i] = 0;
	}
	z[r] = 0;
	q.push(make_pair(0, r));
	while (!q.empty()) {
		auto t = q.top();
		q.pop();
		if (x[t.second] == 1) {
			continue;
		}
		x[t.second] = 1;
		for (auto& e : p[t.second]) {
			ll h = z[t.second] + e.second;
			if (z[e.first] > h) {
				z[e.first] = h;
				q.push(make_pair(h, e.first));
			}
		}
	}
	for (ll i = 0; i < v; i++) {
		if (z[i] == inf) {
			cout << "INF";
		}
		else {
			cout << z[i];
		}
		cout << "\n";
	}
}

