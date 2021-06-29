#include<stdio.h>
#define MAX 100

/*
  unvisited 0
  visited 1
  finished search 2
  
 */
int g[MAX][MAX], labels[MAX], n, d[MAX], f[MAX], time;


void dfs(int u) {
    int v;
    labels[u] = 1;
    d[u] = ++time;
    for(v=0; v<n; v++){
	if (g[u][v] && labels[v] == 0) {
	    dfs(v);
	}
    }
    labels[u] = 2;
    f[u] = ++time;
	
}

int main() {
    
    int i,u,k,v,j;
    scanf("%d",&n);
    for(i=0;i<MAX;i++){
	for(j=0;j<n;j++){
	    g[i][j]=0;
	}
    }
    for(i=0;i<n;i++){
	scanf("%d %d",&u, &k);
	for(j=0;j<k;j++){
	    scanf("%d",&v);
	    g[u-1][v-1]=1;
	}
    }

    time = 0;
    
    for(i=0; i<MAX; i++) {
	labels[i]=0;
    }
    

    /* ?????????????????????????¨????????????°dfs?????? */
    for(i=0; i<n; i++) {
	if (labels[i]==0) dfs(i);
    }
    /*print result */

    for(i=0; i<n; i++){
	printf("%d %d %d\n", i+1, d[i], f[i]);
    }
    
    return 0;

    
}
