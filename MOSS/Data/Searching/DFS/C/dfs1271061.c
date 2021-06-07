#include <stdio.h>

int G[100][100], d[100], f[100], num[100];
int t = 1;

void depth(int u){
	int i;

	d[u] = t++;
	for (i = 1; i <= num[u]; i++){
		if (d[G[u][i]] == 0)
		{
			depth(G[u][i]);
		}
	}
	f[u] = t++;
}

int main(void)
{
	int i, j, n;
	int u, k;

	scanf("%d", &n);

	//?????????
	for (i = 1; i <= n; i++){
		d[i] = f[i] = 0;
		for (j = 1; j <= n; j++){
			G[i][j] = 0;
		}
	}

	//??£??\???????????¨???
	for (i = 1; i <= n; i++){
		scanf("%d", &u);
		scanf("%d", &num[u]);
		for (j = 1; j <= num[u]; j++){
			scanf("%d", &G[u][j]);
		}
	}

	for (i = 1; i <= n; i++){
		if (d[i] == 0)
		{
			depth(i);
		}
	}

	for (i = 1; i <= n; i++){
		printf("%d %d %d\n", i, d[i], f[i]);
	}

	return 0;
}
