#include<stdio.h>

#define G_SIZE 100
struct node{
	int d, f, l;
};

int fds(struct node G[][G_SIZE+1], int size, int id, int t)
{
	int i;

	G[id][id].d = t++;
	for(i = 1; i <= size; i++){
		if((G[id][i].l == 1) && (G[i][i].d == 0)){
			 t = fds(G, size, i, t);
		}
	}
	G[id][id].f = t++;
	return(t);
}

int main(int argc, char* argv[])
{
	int u, k, n, v, i, j, t;
	struct node G[G_SIZE+1][G_SIZE+1];

	for(i = 1; i <= G_SIZE; i++){
		for(j = 1; j <= G_SIZE; j++){
			G[i][j].d = 0;
			G[i][j].f = 0;
			G[i][j].l = 0;
		}
	}

	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &u);
		scanf("%d", &k);
		for(j = 0; j < k; j++){
			scanf("%d", &v);
			G[u][v].l = 1;
		}
	}

	t = 1;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if((G[i][j].l == 1) && (G[j][j].d == 0)){
				t = fds(G, n, i, t);
			}
		}
	}

	for(i = 1; i <= n; i++){
		printf("%d %d %d\n", i, G[i][i].d, G[i][i].f);
	}

	return(0);
}
