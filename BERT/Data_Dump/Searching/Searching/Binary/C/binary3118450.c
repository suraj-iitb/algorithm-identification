#include <stdio.h>

int main()
{
	int n, q, x, ans = 0;
	int S[100001];
	int T[50000];
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) { scanf("%d", &S[i]); }
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) { scanf("%d", &T[i]); }

	for(int i = 0; i < q; ++i)
	{
		int l = 0;
		int h = n;
		while(l < h)
		{
			int m = (l + h) / 2;
			if(T[i] == S[m])
			{
				++ans;
				break;
			}
			else if(T[i] < S[m])
			{
				h = m;
			}
			else
			{
				l = m + 1;
			}
		}
	}
	printf("%d\n", ans);
}

