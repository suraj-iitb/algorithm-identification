#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL V, E, r; cin >> V >> E >> r;
		vector<vector<pair<UL, UL>>> G(V);
		rep(i, E) {
			UL a, b, d; cin >> a >> b >> d;
			G[a].push_back({ b, d });
		}
		priority_queue<pair<UL, UL>, vector<pair<UL, UL>>, greater<pair<UL, UL>>> Q;
		Q.push({ 0, r });
		vector<UL> ans(V, (UL) -1);
		while (Q.size()) {
			pair<UL, UL> p = Q.top(); Q.pop();
			if (ans[p.second] != (UL)-1) continue;
			ans[p.second] = p.first;
			for (auto e : G[p.second]) {
				Q.push({ p.first + e.second, e.first });
			}
		}
		rep(i, V) {
			if (ans[i] == (UL)-1) cout << "INF" << endl;
			else cout << ans[i] << endl;
		}
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
