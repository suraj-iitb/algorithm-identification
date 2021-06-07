#include<stdio.h>
#define N 101
 
int v[N][N], d[N], k[N];
int n;
 
void Distance(int a, int b)
{
  int i;
  d[a] = b;
  for (i = 1; i <= k[a]; i++) {
    if (b + 1 < d[v[a][i]])
        Distance(v[a][i], b + 1);
  }
}
 
int main()
{
  int i, j, u;
 
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    d[i] = 100000000;
    scanf("%d", &u);
    scanf("%d", &k[u]);
    for(j = 1; j <= k[u]; j++)
      scanf("%d", &v[u][j]);
  }
 
  Distance(1, 0);
 
  for (i = 1; i <= n; i++) {
     if (d[i] == 100000000)
         d[i] = -1;
  }
 
  for (i = 1; i <= n; i++)
     printf("%d %d\n", i, d[i]);
 
  return 0;
}
