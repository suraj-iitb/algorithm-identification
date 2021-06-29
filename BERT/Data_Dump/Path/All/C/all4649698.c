#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll INF = 1LL << 60;

ll dp[110][110];

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<pair<int, ll>>> g(v);

	for (int i = 0; i < e; i++) {
		int s, t;
		ll d;
		cin >> s >> t >> d;
		g[s].push_back({ t, d });
	}

	for (int i = 0; i < v - 1; i++) {
		for (int j = i + 1; j < v; j++) {
			dp[i][j] = INF;
			dp[j][i] = INF;
			for (auto to : g[i]) {
				if (j == to.first) dp[i][j] = to.second;
			}
			for (auto to : g[j]) {
				if (i == to.first) dp[j][i] = to.second;
			}
		}
	}

	bool negative = false;

	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (dp[i][k] == INF || dp[k][j] == INF) continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				if (dp[i][i] < 0) negative = true;
			}
		}
	}

	if (negative) cout << "NEGATIVE CYCLE" << endl;
	else {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (dp[i][j] == INF) cout << "INF";
				else cout << dp[i][j];
				if (j < v - 1) cout << " ";
			}
			cout << endl;
		}
	}

	return 0;
}

