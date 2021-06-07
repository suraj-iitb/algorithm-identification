#include<stdio.h>

#define N 101
#define Whi 0
#define Gra 1
#define Bra 2


int M[N][N],color[N],d[N],f[N];
int n,tt;
void visit(int x){
  int v;
  color[x] = Gra;
  d[x] = ++tt;
  for(v=0;v<n;v++){
    if(M[x][v] == 0) continue;
    if(color[v] == Whi){
      visit(v);
    }
  }
  color[x] = Bra;
  f[x] = ++tt;
}


void dfs(){
  int u;

  for(u = 0; u < n; u++) color[u] = Whi;
  tt = 0;

  for(u = 0; u < n; u++){
    if(color[u] == Whi) visit(u);
  }
  for(u = 0; u < n; u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}


int main(){
  int u,v,k,i,j;

  scanf("%d",&n);
  for(i = 0; i<n; i++){
    for(j = 0; j<n;j++) M[i][j] = 0;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      v--;
      M[u][v] = 1;
    }
  }
  dfs();

  return 0;
}

