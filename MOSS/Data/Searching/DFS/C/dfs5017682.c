#include<stdio.h>
#define n_MAX 101

int A[n_MAX][n_MAX]={0};
int d[n_MAX]={0};
int f[n_MAX]={0};
int state[n_MAX]={0};
int time=0;
int n;

void Depth_first_search(int u)
{
  int i;
  state[u] = 1;
  time++;
  d[u]=time;

  for( i = 1; i <= n; i++ )
  {
    if( A[u][i] == 1 && state[i] == 0) Depth_first_search(i);
  }
  state[u] = 2;
  time++;
  f[u]=time;
}

int main(void)
{
  int u, k, v, i, j;

  scanf("%d", &n);
  for( i = 1; i <= n; i++ )
  {
    scanf("%d %d", &u, &k);
    for( j = 1; j <= k; j++ )
    {
      scanf("%d", &v);
      A[u][v]=1;
    }
  }

  for( i = 1; i <= n; i++)
  {
    if(state[i]==0) Depth_first_search(i);
  }

  for( i = 1; i <= n; i++)
  {
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  return 0;
}
