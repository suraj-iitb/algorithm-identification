#include <stdio.h>
#define N 101
#define WHITE 1
#define GRAY 2
#define BLACK 3
int n;
int adj[N][N];
int d[N];
int f[N];
int time;
int color[N];

void DFS(void);
void DFS_Visit(int);

void DFS(void){
	int i;
	for(i=1; i<=n; i++){
		color[i]=WHITE;
		time=0;
	}
	for(i=1; i<=n; i++){
		if(color[i]==WHITE){
			DFS_Visit(i);
		}
	}
}
void DFS_Visit(int u){
	int i;
	color[u]=GRAY;
	d[u]=++time;
	for(i=1; i<=n; i++){
		if(adj[u][i]==1 && color[i]==WHITE){
			DFS_Visit(i);
		}
	}
	color[u]=BLACK;
	f[u]=++time;
}
int main(void){
	int i;
	int j;
	int a, b, c;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			adj[i][j]=0;
		}
	}
	for(i=1; i<=n; i++){
		scanf("%d %d ", &a, &b);
		for(j=1;j<=b;j++){
			scanf("%d", &c);
			adj[a][c]=1;
		}
	}
	DFS();
	for(i=1; i<=n; i++){
		printf("%d %d %d\n", i, d[i], f[i]);
	}
	return 0;
}
