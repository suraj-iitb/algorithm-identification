#include<stdio.h>
#define N 100 
#define white 0
#define gray 1
#define black 2

int M[N][N],colour[N],d[N],f[N],time,n;

void dfs_init(int u)
{
	int v;
	colour[u]=gray;
	d[u]=++time;
	for(v=0;v<n;v++){
		if(M[u][v]&&colour[v]==white){
			dfs_init(v);
        }
    }
	colour[u]=black;
	f[u]=++time;
}

void dfs(int u)
{
	for(u=0;u<n;u++){
		colour[u]=white;
	}
	time=0;
	
	for(u=0;u<n;u++){
		if(colour[u]==white){
			dfs_init(u);
		}
	}
    for(u=0;u<n;u++){
		printf("%d %d %d\n",u+1,d[u],f[u]);
	}
}

int main()
{
	int i,j,u,v,k;
	
	scanf("%d",&n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			M[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){
		scanf("%d",&u);
        scanf("%d",&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			M[u-1][v-1]=1;
		}
	}
	
	dfs(n);
	
	return 0;
}
