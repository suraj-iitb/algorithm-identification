#include <stdio.h>
#define MAX 101
#define inf 99999
#define NIL -1

int A[MAX][MAX], B[MAX], C[MAX];

void Serch(int,int);

int main()
{
  int i,j;
  int k,n;
  
  scanf("%d", &n);
  for(i=1; i<=n; i++)
    {
      C[i] = inf;
      scanf("%d", &k);
      scanf("%d", &B[k]);
      for(j=1; j<=n; j++) A[i][j] = 0;
      for(j=1; j<=B[k]; j++) scanf("%d", &A[k][j]);
    }
  
  Serch(1,0);
  
  for(i=1; i<=n; i++)
    {
      if(C[i] == inf) C[i] = NIL;
      printf("%d %d\n", i, C[i]);
    }
  return 0;
}
  
void Serch(int x, int y)
{
  int i;
  C[x] = y;
  for(i=1; i<=B[x]; i++)
    {
      if(C[A[x][i]] > y)
	Serch(A[x][i], y+1);
    }
}

