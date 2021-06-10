#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long int ll;
ll d[100][100];
const ll INF = 1000000000000000;

void init() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
}

int main()
{
	init();
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		ll s, t, w;
		cin >> s >> t >> w;
		d[s][t] = w;
	}
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 0; i < v; i++) {
		if (d[i][i] < 0) {
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (j != 0) cout << " ";
			if (d[i][j] > 1000000000000) {
				cout << "INF";
			}
			else {
				cout << d[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
