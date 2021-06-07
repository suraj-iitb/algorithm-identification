#include<stdio.h>

int M[101][101];
int dis[101];
int queue[101];

void bfs(int n)
{
  int i;
  for(i = 1;i <= n;i++)
   dis[i]=-1;
  
  int head=0,tail=0;
  queue[tail++]=1;
  dis[1]=0;
  
  while(head != tail){
   int v=queue[head++];
   
   for(i = 1;i <= n;i++){
    if(dis[i]==-1 && M[v][i]==1){
     dis[i]=dis[v]+1;
     queue[tail++]=i;
    }
   }
  }
}
int main()
{
    int n,i,j,u,v,k;
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);

	for(j=0;j<k;j++){
            scanf("%d",&v);
            M[u][v]=1;
        }
    }
    bfs(n);
    for(i = 1;i <= n;i++){
        printf("%d %d\n",i, dis[i]);
    }
    return 0;
}


