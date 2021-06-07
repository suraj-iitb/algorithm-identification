#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n, M[N][N];
int color[N], d[N], f[N], t;

void visit(int i)
{
   int v;
   color[i] = G;
   d[i] = ++t;

   for (v=0; v<n; v++){
      if (M[i][v]==0)
         continue;
      if (color[v]==W)
         visit(v);
   }
   color[i] = B;
   f[i] = ++t;
}

void dfs()
{
   int i;
   for (i=0; i<n; i++)
      color[i] = W;
      t=0;
   for (i=0; i<n; i++){
      if (color[i]==W)
            visit(i);
   }
   for (i=0; i<n; i++)
      printf("%d %d %d\n", i+1, d[i], f[i]);
}

int main()
{
   int u, v, k, i, j;

   scanf("%d", &n);
   for (i=0; i<n; i++){
      for (j=0; j<n; j++)
         M[i][j] = 0;
   }

   for (i=0; i<n; i++){
      scanf("%d %d",  &u, &k);
      u--;
      for (j=0; j<k; j++){
         scanf("%d", &v);
         M[u][v-1] = 1;
      }
   }

   dfs();

   return 0;
}

