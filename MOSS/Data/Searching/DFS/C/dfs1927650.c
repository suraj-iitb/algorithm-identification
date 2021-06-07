#include<stdio.h>
#define N_MAX 120
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n, M[N_MAX][N_MAX];
int color[N_MAX], d[N_MAX], f[N_MAX], t;

void visit(int u);
void dfs();

void visit(int u)
{
	int v;

	color[u] = GRAY;
	d[u] = ++t;
	for(v=0; v<n; v++){
		if(M[u][v] == 0) continue;
		if(color[v] == WHITE){
			visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = ++t;
}

void dfs()
{
	int u;
	for(u=0; u<n; u++){
		color[u] = WHITE;
	}
	t=0;

	for(u=0; u<n; u++){
		if(color[u] == WHITE) visit(u);
	}
	for(u=0; u<n; u++){
		printf("%d %d %d\n", u+1, d[u], f[u]);
	}
}


int main()
{
	int u, v, k;
	int i, j;
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			M[i][j] = 0;
		}
	}

	for(i=0; i<n; i++){
		scanf("%d%d", &u, &k);
		u--;
		for(j=0; j<k; j++){
			scanf("%d", &v);
			v--;
			M[u][v] = 1;
		}
	}

	dfs();

	return 0;
}
