#include<stdio.h>

#define S 101
int graph[S][S];
int d[S];
int queue[S];
int n;

void init(){
	int i, j;
	int u, k, v;
	scanf("%d", &n);
	for( i = 1; i <= n; i++ ){
		d[i] = -1;
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

int bfs(int s){
	int i,j;
	int qs=0, qe=0;
	queue[qe++] = s;
	d[s] = 0;
	while( qs < qe ){
		i = queue[qs++];
		for( j = 1; j <= n; j++ ){
			if( graph[i][j] == 1 && d[j] == -1 ){
				queue[qe++] = j;
				d[j] = d[i]+1;
			}
		}
	}
	return 0;
}

void print(){
	int i;
	for( i = 1; i <= n; i++ ){
		printf("%d %d\n", i, d[i]);
	}
	return;
}

int main(){
	int i;
	init();
	bfs(1);
	print();
	return 0;
}
