#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
	const ll INF = 1LL << 32;
	int v, e, i, j, k, s, t;
	ll dp[100][100];

	cin >> v >> e;

	for (i = 0;i < v;i++) {
		for (j = 0;j < v;j++) {
			dp[i][j] = INF;

		}
		dp[i][i] = 0;
	}

	for (i = 0;i < e;i++) {
		cin >> s >> t;
		cin >> dp[s][t];
	}

	for (k = 0;k < v;k++) {
		for (i = 0;i < v;i++) {
			if (dp[i][k] == INF)continue;
			for (j = 0;j < v;j++) {
				if (dp[k][j] == INF)continue;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (i = 0;i < v;i++) {
		if (dp[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}

	for (i = 0;i < v;i++) {
		for (j = 0;j < v - 1;j++) {
			if (dp[i][j] == INF) {
				cout << "INF" << " ";
			}
			else {
				cout << dp[i][j] << " ";
			}
		}

		if (dp[i][j] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << dp[i][j] << endl;
		}
	}

	return 0;
}

