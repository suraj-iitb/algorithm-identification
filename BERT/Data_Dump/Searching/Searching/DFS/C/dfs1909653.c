#include <stdio.h>
#define N 100
int n,a[N][N];
//
#define W 0
#define G 1
#define B 2
int color[N],d[N],f[N],tt;

void dfs_visit(int u){
	int v;
	color[u] = G;
	d[u] = ++tt;
	for(v=0;v<n;v++){
		if(a[u][v] == 0)continue;
		if(color[v] == W){
			dfs_visit(v);
		}
	}
	color[u] = B;
	f[u] = ++tt;
}

void dfs(){
	int u;
	for(u=0;u<n;u++)color[u] = W;
		tt = 0;

	for(u=0;u<n;u++){
		if(color[u] == W)dfs_visit(u);
	}
	for(u=0;u<n;u++){
		printf("%d %d %d\n",u+1,d[u],f[u]);
	}
}


int main(){
	int i,j,u,k,v;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)a[i][j]=0;
	}

	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			a[u-1][v-1] = 1;
		}
	}

	dfs();

	return 0;
}