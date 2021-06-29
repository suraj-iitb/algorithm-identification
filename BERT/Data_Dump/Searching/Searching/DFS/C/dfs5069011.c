#include<stdio.h>

#define N 100
#define white 0
#define gray 1
#define black 2

int M[N][N];
int n;
int color[N], d[N], f[N], tt;

void dfs_visit(int u){//再起関数による深さ優先探索
	int v;
	color[u] = gray;
	d[u] = ++tt;//最初の訪問
	for(v=0 ; v<n ; v++){
		if(M[u][v] == 0) continue;
		if( color[v] == white ){
			dfs_visit(v);
		}
	}
	color[u] = black;
	f[u] = ++tt;//訪問の完了
}

void dfs(){
	int u;
	for( u=0 ; u<n ; u++) color[u] = white;
	tt = 0;
	
	for( u=0 ; u<n ; u++){
		if(color[u] == white) dfs_visit(u);
	}
	for(u=0 ; u<n ; u++){
		printf("%d %d %d\n", u+1,d[u],f[u]);
	}
}

int main(){
	int u,v,k,i,j;
	
	scanf("%d", &n);
	for( i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++) M[i][j] = 0;
	}
	
	for(i=0 ; i<n ; i++){
		scanf("%d %d",&u, &k);
		u--;
		for(j=0 ;j<k ; j++){
			scanf("%d",&v);
			v--;
			M[u][v] = 1;
		}
	}
	
	dfs();
	
	return 0;
}

