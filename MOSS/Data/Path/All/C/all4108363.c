#include <vector>
#include <iostream>
#include <stdio.h>
#include <functional>
#include <cassert>
#define INF 2000000000000000

using namespace std;

int main() {
	int v, e, s, t, d;
	cin >> v >> e;
	vector<vector<long long> > ans(v, vector<long long>(v, INF));
	
	for (int i = 0; i < e; ++i) {
		cin >> s >> t >> d;
		ans[s][t] = d;
	}
	for (int i = 0; i < v; ++i) {
		ans[i][i] = 0;
	}

	for (int k = 0; k < v; ++k) {
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				if (ans[i][j] > ans[i][k] + ans[k][j] && ans[i][k] != INF && ans[k][j] != INF) {
					ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < v; ++i) {
		if (ans[i][i] != 0) {
			flag = true;
		}
	}
	if (flag) {
		cout << "NEGATIVE CYCLE" << endl;
	}
	else {
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v - 1; ++j) {
				if (ans[i][j] != INF) {
					cout << ans[i][j] << " ";
				}
				else {
					cout << "INF ";
				}
			}
			if (ans[i][v - 1] != INF) {
				cout << ans[i][v - 1] << endl;
			}
			else {
				cout << "INF" << endl;
			}
		}
	}
	return 0;
}
