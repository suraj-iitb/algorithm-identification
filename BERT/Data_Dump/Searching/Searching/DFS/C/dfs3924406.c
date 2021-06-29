#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100

struct node {
	int d;
	int f;
	int pnum;
	struct node **paths;
} nodes[N_MAX+1] = {0};

int time = 0;
int rest = 0;

void
dfs(struct node *arg)
{
	int i;

	time++;
	arg->d = time;

	for (i = 0; i < arg->pnum; i++)
		if (arg->paths[i]->d == 0)
			dfs(arg->paths[i]);

	time++; /* 時刻の定義は謎 */
	arg->f = time;
	rest--;
}

int
main(void)
{
	int i, n;
	int umin = N_MAX, umax = 0;

	scanf("%d", &n);
	rest = n;
	for (i = 0; i < n; i++) {
		int j, u, k, p;

		scanf("%d%d", &u, &k);

		if (umin > u)
			umin = u;
		if (umax < u)
			umax = u;

		nodes[u].pnum = k;
		if (k == 0)
			continue;

		nodes[u].paths = (struct node **)malloc(sizeof(struct node *) * k);
		if (nodes[u].paths == NULL)
			return 1;

		for (j = 0; j < k; j++) {
			scanf("%d", &p);
			nodes[u].paths[j] = nodes + p;
		}
	}

	for (i = umin; i <= umax && rest > 0; i++)
		if (nodes[i].d == 0)
			dfs(nodes + i);

	for(i = 1; i <= n; i++) {
		printf("%d %d", i, nodes[i].d);
		if (nodes[i].f > 0)
			printf(" %d", nodes[i].f);
		printf("\n");
	}

	return 0;
}

