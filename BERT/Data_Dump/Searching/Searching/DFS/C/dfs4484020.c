#include<stdio.h>
#define N 100
int n,M[N][N];
int color[N],d[N],f[N],start;
void dfs_visit(int u){
	color[u] = 1;
	d[u] = ++start;
	for(int i=0;i<n;i++){
		if(!M[u][i]) continue;
		if(!color[i])
			dfs_visit(i);
	}
	f[u] = ++start;
}
void dfs(){
	start = 0;
    for(int i=0;i<n;i++)
            if(!color[i])
	            dfs_visit(i);
	for(int i=0;i<n;i++)
		printf("%d %d %d\n",i+1,d[i],f[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int u,k,v;
		scanf("%d%d",&u,&k);
		while(k--){
			scanf("%d",&v);
			M[u-1][v-1] = 1;
		}
	}
	dfs();
	return 0;
}
