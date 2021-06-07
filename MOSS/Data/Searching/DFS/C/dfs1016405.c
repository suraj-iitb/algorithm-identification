#include<stdio.h>
#define MAX 105
#define WHITE 0
#define GRAY 1
#define BLACK 2
void DFS(void);
void DFSVisit(int);

int G[MAX][MAX];
int d[MAX];
int f[MAX];
int color[MAX];
int n;
int time;

int main(){

	int i,j,u,k,next;

	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			G[i][j] = 0;
		}
	}
	for(i = 1; i <= n;i++){
		scanf("%d%d",&u,&k);
		for(j = 1; j <= k; j++){
			scanf("%d",&next);
			G[i][next] = 1;
		}
	}
	DFS();
	for(i = 1; i <= n; i++){
		printf("%d %d %d\n",i,d[i],f[i]);
	}

	return 0;
}

void DFS(void){

	int u;

	for(u = 1; u <= n; u++){
		color[u] = WHITE;
	}
	time = 0;
	for(u = 1; u <= n; u++){
		if(color[u] == WHITE)
			DFSVisit(u);
	}
}

void DFSVisit(int u){

	int v;

	color[u] = GRAY;
	d[u] = ++time;
	for(v = 1; v <= n; v++){
		if(G[u][v] == 1 && color[v] == WHITE)
			DFSVisit(v);
	}
	color[u] = BLACK;
	f[u] = ++time;
}
