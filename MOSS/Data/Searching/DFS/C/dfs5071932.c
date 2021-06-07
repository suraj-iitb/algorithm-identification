#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[N][N];
int C[N],d[N],f[N],t;

void depth(int u){
	int i;
	C[u] = GRAY;
	d[u] = ++t; //はじめ
	for(i=0;i<n;i++){
		if(M[u][i] == 0) continue;
		if(C[i] == WHITE){
			depth(i);
		}
	}
	C[u] = BLACK;
	f[u] = ++t; //おわり
}



int main(void){
	int u,k,v,i,j;
	
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
			M[u][v]=1;
		}
	}
	for(i=0;i<n;i++)C[i] = WHITE;
	t = 0;
	
	for(i=0;i<n;i++){
		if(C[i] == WHITE)depth(i);
	}
	for(i=0;i<n;i++){
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
	
	
	return 0;
}

