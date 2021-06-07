#include <stdio.h>
#define N 101

int G[N][N], X[N], Y[N], n;

void find(int x, int y){
	int i;
	X[x] = y;
	for(i=1; i<=Y[x]; i++)
	if(y+1 < X[G[x][i]]) find(G[x][i], y+1);
}

int main(){
	int i, j, m;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		X[i] = 100000000;
		scanf("%d", &m);
		scanf("%d", &Y[m]);
		
		for(j=1; j<=Y[m]; j++)
		scanf("%d", &G[m][j]);
	}
	
	find(1, 0);
	
	for(i=1; i<=n; i++)
	if(X[i] == 100000000)  X[i] = -1;
	
	for(i=1; i<=n; i++)
	printf("%d %d\n", i, X[i]);
	
	return 0;
}
