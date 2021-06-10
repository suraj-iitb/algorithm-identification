#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL V, E; cin >> V >> E;
		vector<pair<pair<UL, UL>, LL>> G(E);
		rep(i, E) {
			UL a, b; LL d; cin >> a >> b >> d;
			G[i] = { { a, b }, d };
		}
		rep(r, V) {
			const LL INF = 1000000000000;
			vector<LL> ans(V, INF);
			ans[r] = 0;
			rep(i, V - 1) {
				for (auto e : G) {
					UL u = e.first.first, v = e.first.second;
					LL d = e.second;
					if (ans[u] == INF) continue;
					ans[v] = min(ans[v], ans[u] + d);
				}
			}
			for (auto e : G) {
				UL u = e.first.first, v = e.first.second;
				LL d = e.second;
				if (ans[u] == INF) continue;
				if (ans[v] > ans[u] + d) { cout << "NEGATIVE CYCLE" << endl; return; }
			}
			rep(i, V) {
				if (i) cout << " ";
				if (ans[i] == INF) cout << "INF";
				else cout << ans[i];
			} cout << endl;
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
