#include <stdio.h>

int G[100][100], num[100], width[100];

void depth(int u, int t){
	int i;
	width[u] = t;
	for (i = 1; i <= num[u]; i++){
		if (width[G[u][i]] > t)
		{
			depth(G[u][i], t + 1);
		}
	}
}

int main(void)
{
	int i, j, n;
	int u;

	scanf("%d", &n);

	//?????????
	for (i = 1; i <= n; i++){
		width[i] = 10000;
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

	depth(1, 0);

	for (i = 1; i <= n; i++){
		if (width[i] == 10000)
		{
			width[i] = -1;
		}
		printf("%d %d\n", i, width[i]);
	}

	return 0;
}
