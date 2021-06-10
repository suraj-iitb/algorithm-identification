#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e18;

signed main(void)
{
	int v, e;
	cin >> v >> e;
	ll M[v][v];
	rep(i, v) rep(j, v) M[i][j] = INF;
	rep(i, v) M[i][i] = 0;
	rep(i, e)
	{
		int a, b, c;
		cin >> a >> b >> c;
		M[a][b] = c;
	}
	rep(k, v) rep(i, v) rep(j, v)
	{
		if (M[i][k] == INF || M[k][j] == INF) continue;
		M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
	}
	rep(i, v)
	{
		if (M[i][i] < 0)
		{
			cout << "NEGATIVE CYCLE" << endl;
			return 0;
		}
	}
	rep(i, v) rep(j, v) 
	{
		if (M[i][j] == INF)
			cout << "INF";
		else
			cout << M[i][j];
		printf("%c", j == v - 1 ? '\n' : ' ');
	}
	return 0;
}


