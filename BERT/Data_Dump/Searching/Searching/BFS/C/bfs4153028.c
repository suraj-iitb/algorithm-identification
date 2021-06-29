#include<stdio.h>
int matrix[105][105];
int lv[105];
int queue[105];
void Bfs(int n)
{
  int i;
  for(i=1;i<=n;i++)
   lv[i]=-1;
  int qHead=0,qTail=0;
  queue[qTail++]=1;
  lv[1]=0;
  while(qHead!=qTail){
   int v=queue[qHead++];
   for(i=1;i<=n;i++){
    if(lv[i]==-1 && matrix[v][i]==1){
     lv[i]=lv[v]+1;
     queue[qTail++]=i;
    }
   }
  }
}
int main()
{
    int n,i,j,u,v,fg;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&u,&fg);
        for(j=0;j<fg;j++){
            scanf("%d",&v);
            matrix[u][v]=1;
        }
    }
    Bfs(n);
    for(i=1;i<=n;i++){
        printf("%d %d\n",i, lv[i]);
    }
    return 0;
}


