#include<stdio.h>

#define S 101
int graph[S][S];
int d[S];
int f[S];
int n;

void init(){
	int i, j;
	int u, k, v;
	scanf("%d", &n);
	for( i = 1; i <= n; i++ ){
		d[i] = -1;
		f[i] = -1;
		for( j = 1; j <= n; j++ ){
			graph[i][j] = 0;
		}
	}
	for( i = 1; i <= n; i++ ){
		scanf("%d", &u);
		scanf("%d", &k);
		for( j = 0; j < k; j++ ){
			scanf("%d", &v);
			graph[i][v] = 1;
		}
	}
	return;
}

void printGraph(){
	int i, j;
	for( i = 1; i <= n; i++ ){
		for( j = 1; j < n; j++ ){
			printf("%d ", graph[i][j]);
		}
		printf("%d\n", graph[i][n]);
	}
	return;
}

int dfs(int i, int c){
	int j;
	d[i] = ++c;
	for( j = 1; j <= n; j++ ){
		if( graph[i][j] == 1 && d[j] == -1 ){
			c = dfs(j, c);
		}
	}
	f[i] = ++c;
	return c;
}

void print(){
	int i;
	for( i = 1; i <= n; i++ ){
		printf("%d %d %d\n", i, d[i], f[i]);
	}
	return;
}

int main(){
	int i, c = 0;
	init();
	for( i = 1; i <= n; i++ ){
		if( d[i] == -1 ){ c = dfs(i, c); }
	}
	print();
	return 0;
}
