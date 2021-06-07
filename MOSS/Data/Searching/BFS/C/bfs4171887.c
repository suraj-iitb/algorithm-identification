#include<stdio.h>
#define N 105

int M[N][N];
int l[N];
int queue[N];


void bfs(int n)
{
  int i;
  for(i=1;i<=n;i++)
    l[i]=-1;
  int qH=0,qT=0;
  queue[qT++]=1;
  l[1]=0;
  while(qH!=qT){
    int v=queue[qH++];
    for(i=1;i<=n;i++){
      if(l[i]==-1 && M[v][i]==1){
	l[i]=l[v]+1;
	queue[qT++]=i;
      }
    }
  }
}
int main()
{
  int n,i,j,u,v,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&r);
    for(j=0;j<r;j++){
      scanf("%d",&v);
      M[u][v]=1;
    }
  }
  bfs(n);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i, l[i]);
  }
  return 0;
}

