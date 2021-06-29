#include <stdio.h>

int main()
{
	int n, q, x, ans = 0;
	int S[10001];
	int T[500];
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) { scanf("%d", &S[i]); }
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) { scanf("%d", &T[i]); }

	for(int i = 0; i < q; ++i)
	{
		// 番兵設定
		S[n] = T[i];

		// 線形探索
		x = 0;
		while(S[x] != T[i])
		{
			++x;
		}

		// 番兵でなければカウント
		if(x != n)
		{
			++ans;
		}
	}
	printf("%d\n", ans);
}

