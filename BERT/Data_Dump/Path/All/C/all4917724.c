#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 110;
int n, m;
ll mp[maxn][maxn];

bool floyd()
{
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (mp[i][k]!=inf&&mp[k][j]!=inf)mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
	for (int i = 0; i < n; ++i)
		if (mp[i][i] < 0)
			return 1;
	return 0;
}

int main()
{
	scanf("%d %d", &n, &m);
	memset(mp, 0x3f, sizeof(mp));
	for (int i = 0; i < 100; ++i) mp[i][i] = 0;
	for (int i = 1, u, v, w; i <= m; ++i)
		scanf("%d %d %d", &u, &v, &w), mp[u][v] = w;
	if (floyd())
		puts("NEGATIVE CYCLE");
	else
	{
		for (int i = 0; i < n; ++i, puts(""))
			for (int j = 0; j < n; ++j)
			{
				if (j) putchar(' ');
				if (mp[i][j]==inf)
					printf("INF");
				else
					printf("%lld", mp[i][j]);
			}
	}
	return 0;
}
