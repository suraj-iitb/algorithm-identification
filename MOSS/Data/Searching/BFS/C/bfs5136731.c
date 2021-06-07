#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void bfs(int);

int n, A[101][101],color[101],d[101],Q[101];

int main(void){
	int u, k, v;
	scanf("%d", &n);
	
	int i,j;
	
	for(i = 1;i <= n;i++){
		color[i] = WHITE;
		d[i] = -1;
		Q[i] = -1;
		
		for(j = 1; j <= n; j++){
			A[i][j] = 0;
		}
	}
	
	for(i = 1;i <= n;i++){
		scanf("%d%d",&u,&k);
		for(j = 1;j <= k;j++){
			scanf("%d",&v);
			A[u][v] = 1;
		}
	}
	
	bfs(1);
	
	for(i = 1; i <= n; i++){
		{
			printf("%d %d\n", i, d[i]);
		}
	}
	return 0;
}

void bfs(int s){
	int u,v,i;
	
	color[s] = GRAY;
	d[s] = 0;
	Q[1] = s;
	
	while(Q[1] != -1){
		u = Q[1];
		
		for(i = 1;Q[i] != -1;i++){
			Q[i] = Q[i+1];
		}
		
		for(v = 1;v <= n;v++){
			if(color[v] == WHITE && A[u][v] == 1)
			{
				color[v] = GRAY;
				d[v] = d[u] + 1;
				
				for(i = 1; ; i++){
					if(Q[i] == -1)
					{
						Q[i] = v;
						break;
					}
				}
			}
		}
		color[u] = BLACK;
	}
}

