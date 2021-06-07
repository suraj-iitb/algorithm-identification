#include<stdio.h>
#define NA 100
#define WH 0
#define GA 1
#define BL 2

int n, M[NA][NA];
int color[NA], d[NA], f[NA], tt;

void DfsVisit(int u){
  int v;

  color[u]= GA;
  d[u] = ++tt;

  for(v=0; v<n; v++)
  {
    if(M[u][v] == 0) continue;
    if(color[v] == WH)
    {
      DfsVisit(v);
    }
  }
  color[u]=BL;
  f[u] = ++tt;
}

void Dfs(){
  int u;

  for(u=0; u<n; u++) color[u]=WH;
  tt=0;

  for(u=0; u<n; u++)
  {
    if(color[u] == WH) DfsVisit(u);
  }
  for(u=0; u<n; u++)
  {
    printf("%d %d %d\n", u+1, d[u], f[u]);
  }
}

int main(){
  int u, v, k, i, j;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    for(j=0; j<n; j++) M[i][j]=0;
  }

  for(i=0; i<n; i++)
  {
    scanf("%d %d", &u, &k);
    u--;
    for(j=0; j<k; j++)
    {
      scanf("%d", &v);
      v--;
      M[u][v]=1;
    }
  }

  Dfs();

  return 0;
}

