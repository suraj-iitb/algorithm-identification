#include<stdio.h>

void bfs(int ,int);

int A[101][101];
int B[101];
int n;

int main()
{
  int i,j,num,k,v;
 /* num=頂点の番号、k=uの出次数、v=隣接する頂点の番号*/
 
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d %d",&num,&k);

    for(j=0;j<k;j++)
    {
      scanf("%d",&v);
      A[num][v]=1;
    }

  }
  for(i=1;i<=n;i++)
  {
      B[i]=-1;
  }
  bfs(1,0);
 
  for(i=1;i<=n;i++)
  {
    printf("%d %d",i,B[i]);
    printf("\n");
  }

  return 0;
}


void bfs(int x,int num)
{
  int i;
  B[x]=num;

  for(i=1;i<=n;i++)
  {
    if(A[x][i]==1)
    {
      if(B[i]==-1 || B[i]>num+1) bfs(i,num+1);
    }
  }

}


