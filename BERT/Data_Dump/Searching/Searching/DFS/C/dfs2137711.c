#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int M[100][100];
int f[100], d[100], tt, n, color[100];

void df_d(int u) {
  int v;
  color[u]=GRAY;
  d[u]=++tt;
  for (v=0; v<n; v++) {
    if (M[u][v]==0) continue;
    if (color[v]==WHITE) {
      df_d(v);
    }
  }
  color[u]=BLACK;
  f[u]=++tt;
}

void df_f() {
  int u;
  for(u=0; u<n; u++)
    color[u]=WHITE;
  tt=0;

  for (u=0; u<n; u++) {
    if (color[u]==WHITE) df_d(u);
  }
  for (u=0; u<n; u++) {
    printf("%d %d %d\n",u+1, d[u], f[u]);
  }
}

int main() {

  int  u, k, i, j, v;

  scanf("%d", &n);

  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      M[i][j]=0;

  for (i=0; i<n; i++) {
    scanf("%d %d", &u, &k);
    u=u-1;
    for (j=0; j<k; j++) {
      scanf("%d", &v);
      v=v-1;
      M[u][v]=1;
    }
  }

  df_f();

  return 0;

}
