#include<stdio.h>
#define N 100

int l[N][N],n,flg[N];
int d[N],f[N],t;

void DFS(int );
void INDFS();

int main(){
  int i,j,u,v,k;
  scanf("%d",&n);
  for(i = 0; i<n; i++){
    for(j = 0; j<n; j++){
      l[i][j] = 0;
    }
  }

  for(i = 0; i<n ; i++){
    scanf("%d%d",&u,&k);
    for(j = 0; j<k; j++){
      scanf("%d",&v);
      l[u-1][v-1] = 1;
    }
  }
  INDFS();

  return 0;
}

void DFS(int u){
  int v;
  flg[u] = 1;
  ++t;
  d[u]  = t;
  for(v = 0; v<n; v++){
    if(l[u][v] == 0){
      continue;
    }
    if(flg[v] == 0){
      DFS(v);
    }
  }
  flg[u] = 2;
  ++t;
  f[u] = t;
}

void INDFS(){
  int i,j,l;
  for(i = 0; i<n; i++){
    flg[i] = 0;
  }
  t = 0;
  for(j = 0; j<n; j++){
    if(flg[j] == 0){
      DFS(j);
    }
  }
    for(l = 0; l<n; l++){
      printf("%d %d %d\n", l+1,d[l],f[l]);
    }
  }

