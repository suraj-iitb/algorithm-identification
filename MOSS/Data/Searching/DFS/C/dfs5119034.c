#include <stdio.h>

int node[101][101];
int time[101][2];
int visit[101];

int dfs(int n, int t)
{
    int i;
	/*int node[101][101];
	int time[101][2];
	int visit[101];*/
    
	visit[n]=1;
    
	if(time[n][0]==0){
    	time[n][0] = t;
    }
	
	for(i=1;i<=node[n][0];i++){
		if (node[n][i]!=0&&visit[node[n][i]]==0){
			t=dfs(node[n][i],t+1);
        }
    }
	
	t++;
	time[n][1] = t;
    
	return t;
}

int main(void)
{
    int n,u,k,t,i,j;
	/*int node[101][101];
	int time[101][2];
	int visit[101];*/
    
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&u,&k);
        
        node[u][0]=k;
    	
        for(j=1;j<=k;j++){
            scanf("%d",&node[u][j]);
        }
    }
    
    t=0;
    for(i=1;i<=n;i++){
        if(visit[i]==0){
            t=dfs(i,t+1);
        }
    }
    
	for(i=1;i<=n;i++){
        printf("%d %d %d\n",i,time[i][0],time[i][1]);
    }
	
    return 0;
}
