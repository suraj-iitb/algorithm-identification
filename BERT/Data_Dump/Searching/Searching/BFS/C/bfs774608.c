#include<stdio.h>

#define G_SIZE 100
struct node{
	int d, l;
};

int buff[10000], qi, qj;
void enque(int id)
{
	buff[qj++] = id;
	return;
}

int deque(void)
{
	if(qi < qj){
		return(buff[qi++]);
	}
	return(-1);
}

void bfs(struct node G[][G_SIZE+1], int size, int id)
{
	int u, v, i;
	enque(id);
	while((u = deque()) != -1){
		if(u == 1){
			G[u][u].d = 0;
		}
		for(i = 1; i <= size; i++){
			if((G[u][i].l == 1) && (G[i][i].d == -1)){
				v = i;
				G[v][v].d = G[u][u].d + 1;
				enque(v);
			}
		}
	}
	return;
}

int main(int argc, char* argv[])
{
	int u, k, n, v, i, j;
	struct node G[G_SIZE+1][G_SIZE+1];

	for(i = 1; i <= G_SIZE; i++){
		for(j = 1; j <= G_SIZE; j++){
			G[i][j].d = -1;
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

	bfs(G, n, 1);

	for(i = 1; i <= n; i++){
		printf("%d %d\n", i, G[i][i].d);
	}

	return(0);
}
