#include <stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[N][N];
int op[N],d[N],f[N],time;

void dfs(int u){
	int v;
	op[u] = GRAY;
	d[u] = ++time;
	for(v=0;v<n;v++){
		if(M[u][v] && op[v] == 0){
			dfs(v);
		}
	}
	op[u] = BLACK;
	f[u] = ++time;

}

int main(void){

	int u,v,k,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<N;i++){
    	for(j=0;j<n;j++){
        	M[i][j]=0;
    	}
	}
	
	for(i=0;i<n;i++){
    scanf("%d %d",&u, &k);
    for(j=0;j<k;j++){
        scanf("%d",&v);
        M[u-1][v-1]=1;
   		}
    }
	
	time = 0;
     
    for(i=0; i<N; i++) {
    	op[i]=0;
    }
	
	for(i=0; i<n; i++) {
    	if (op[i]==0) dfs(i);
    }
 
    for(i=0; i<n; i++){
    	printf("%d %d %d\n", i+1, d[i], f[i]);
    }


return 0;


}

