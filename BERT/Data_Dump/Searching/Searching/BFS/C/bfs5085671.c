#include <stdio.h>
#define N 100
#define INFTY 100000000

int M[N+1][N+1], vis[N+1], n, size[N+1];

void bfs(int p, int t){
	int i;
	vis[p] = t;
	for(i = 1;i <= size[p];i++){
		if(t + 1 < vis[M[p][i]]){
			bfs(M[p][i], t + 1);
		}
	}
}

int main(void){
	int i, j, k;
	
	scanf("%d", &n);
	
	for(i = 1;i <= n;i++){
		vis[i] = INFTY;
		scanf("%d", &k);
		scanf("%d", &size[k]);
		for(j = 1; j<= size[k];j++){
			scanf("%d", &M[k][j]);
		}
	}
	
	bfs(1, 0);
	
	for(i = 1;i <= n;i++){
		printf("%d %d\n", i, (vis[i] == INFTY) ? - 1 : vis[i]);
	}
	
	return 0;
}
