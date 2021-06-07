#include<stdio.h>

int A[100][100];
int B[100];
int C[100];
int D[100];
int time,n;

void visit(int );
void dfs();

int main(){
  int i,j,k;
  int a,b;

  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      A[i][j] = 0;
    }
  }

  for(i=0;i<n;i++)
  {
    scanf("%d%d",&a,&b);
    for(j=0;j<b;j++)
    {
      scanf("%d",&k);
      A[a-1][k-1] = 1;
    }
  }

  dfs();
  return 0;
}

void visit(int u)
{
  int a;
  D[u] = 1;
  C[u] = ++time;
  for(a=0;a<n;a++)
  {
    if(!A[u][a])continue;
    if(!D[a])visit(a);
  }
  D[u] = 2;
  B[u] = ++time;
}

void dfs()
{
  int d;
  for(d=0;d<n;d++)
  {
    D[d] = 0;
  }
  time = 0;
  for(d=0;d<n;d++)
  {
    if(!D[d])visit(d);
  }
  for(d=0;d<n;d++)
  {
    printf("%d %d %d\n",d+1,C[d],B[d]);
  }
}
