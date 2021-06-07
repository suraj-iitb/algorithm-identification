//Depth First Search
#include<stdio.h>

#define N 100
#define UNVISITED 0
#define VISITED 1
#define VISIT_COMP 2

//Depth First Search
void dfs_visit(int);
void dfs();

int n,M[N][N];
int color[N],d[N],f[N],tt;


int main(){
	int u,v,k,i,j;


	//input
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			M[i][j]=0;
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
	dfs();

	return 0;
}


//再帰関数による深さ優先探索
void dfs_visit(int u){
	int v;

	color[u]=VISITED;
	//最初の訪問
	d[u]= ++tt;
	for(v=0;v<n;v++){
		if(M[u][v]==0){
			continue;
		}
		if(color[v]==UNVISITED){
			dfs_visit(v);
		}
	}
	color[u]=VISIT_COMP;
	//訪問の完了
	f[u]= ++tt;
}

void dfs(){
	int u;

	//init
	for(u=0;u<n;u++){
		color[u]=UNVISITED;
	}
	tt=0;

	for(u=0;u<n;u++){
		//未訪問のuを始点として深さ優先探索
		if(color[u]==UNVISITED){
			dfs_visit(u);
		}
	}
	for(u=0;u<n;u++){
		printf("%d %d %d\n",u+1,d[u],f[u]);
	}
}

