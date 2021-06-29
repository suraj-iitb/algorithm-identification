#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

#include <cstdio>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

#define INF (20000000000000)

ll d[100][100];

int main()
{
	int V, E, s, t, c;
	bool negative = false;

	cin >> V >> E;

	rep(i, V) {
		rep(j, V) d[i][j] = (i == j) ? 0 : INF;
	}

	rep(i, E) {
		cin >> s >> t >> c;
		d[s][t] = c;
	}

	rep(k, V) {
		rep(i, V) {
			if (d[i][k] == INF) continue;
			rep(j, V) {
				if (d[k][j] == INF) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	rep(i, V) if (d[i][i] < 0) negative = true;

	if (negative) cout << "NEGATIVE CYCLE" << endl;
	else {
		rep(i, V) {
			if (d[i][0] == INF) cout << "INF";
			else cout << d[i][0];

			repc(j, 1, V - 1) {
				cout << ' ';

				if (d[i][j] == INF) cout << "INF";
				else cout << d[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
