#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int color[MAX], d[MAX], f[MAX],cnt;
int M[MAX][MAX];

void visit(int u){
	int v;
	color[u] = GRAY;
	d[u] = ++cnt;
	for(v=0;v<n;v++){
		if(M[u][v] == 0) continue;
		if(color[v] == WHITE){
			visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = ++cnt;
}

void print(){
	int u;
	for(u=0;u<n;u++) color[u] = WHITE;
	cnt = 0;

	for(u=0;u<n;u++){
		if(color[u] == WHITE) visit(u);
	}
	for(u=0;u<n;u++){
		printf("%d %d %d\n",u+1,d[u],f[u] );
	}
}

	int main(){
		int u,v,k,i,j;

		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				M[i][j] = 0;
			}
		}

		for(i=0;i<n;i++){
			scanf("%d %d",&u,&k);
			u--;
			for(j=0;j<k;j++){
				scanf("%d",&v);
				v--;
				M[u][v] = 1;
			}
		}

		print();

	return 0;
}
