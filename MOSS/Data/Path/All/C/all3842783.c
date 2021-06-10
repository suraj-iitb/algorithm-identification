#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair <int, int> pii;
typedef pair <pii, int> ppiii;

const int INF = 2147483647;
int n, m, t1, t2, t3, d[105][105];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = INF;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2 >> t3;
		d[t1][t2] = t3;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k) d[j][k] = 0;
				if (d[j][i] == INF || d[i][k] == INF) continue;
				if (d[j][i] + d[i][k] < d[j][k]) {
					d[j][k] = d[j][i] + d[i][k];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k) d[j][k] = 0;
				if (d[j][i] == INF || d[i][k] == INF) continue;
				if (d[j][i] + d[i][k] < d[j][k]) {
					cout << "NEGATIVE CYCLE" << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == INF) cout << "INF";
			else cout << d[i][j];
			if (j < n - 1) cout << ' ';
		}
		cout << endl;
	}
}

