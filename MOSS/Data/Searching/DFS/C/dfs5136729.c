#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);

int n,A[101][101],color[101],d[101],f[101],t = 0;

int main(void){
	int u,v,k;
	
	scanf("%d", &n);
	
	int i,j;
	for(i = 1;i <= n;i++){
		color[i] = WHITE;
		for(j = 1; j <= n; j++){
			A[i][j] = 0;
		}
	}
	
	for(i = 1;i <= n;i++){
		scanf("%d%d", &u, &k);
		
		for(j = 1; j <= k; j++){
			scanf("%d",&v);A[u][v] = 1;
		}
	}
	
	dfs();
	
	for(i = 1;i <= n;i++) printf("%d %d %d\n",i,d[i],f[i]);
	return 0;
}

void dfs(void){
	int u;
	for(u = 1; u <= n; u++){
		if(color[u] == WHITE)
		{
			visit(u);
		}
	}
}

void visit(int u){
	int v;
	color[u] = GRAY;
	d[u] = ++t;
	
	for(v = 1; v <= n; v++){
		if(color[v] == WHITE && A[u][v] == 1)
		{
			visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = ++t;
}
