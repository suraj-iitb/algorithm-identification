#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES puts("YES\n")
#define Yes puts("Yes\n")
#define NO  puts("NO\n")
#define No  puts("No\n")
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }


signed main() {

	int d[100][100];
	int N, M;
	cin >> N >> M;

	rep(i, N)rep(j, N) d[i][j] = INF;
	rep(i, M) {
		int a, b, w;
		cin >> a >> b >> w;
		d[a][b] = w;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			if (d[i][k] == INF) continue;
			for (int j = 0; j < N; j++) {
				if (d[k][j] == INF) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	bool negative = false;
	rep(i, N) if (d[i][i] < 0) negative = true;

	if (negative) cout << "NEGATIVE CYCLE" << endl;
	else {
		rep(i, N) {
			rep(j, N) {
				if (i == j) cout << "0";
				else if (d[i][j] == INF) cout << "INF";
				else
					cout << d[i][j];
				if (j < N - 1) cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
