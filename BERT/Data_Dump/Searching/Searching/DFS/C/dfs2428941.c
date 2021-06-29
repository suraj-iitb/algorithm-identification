#include<stdio.h>
#define N 100
#define X 0
#define Y 1
#define Z 2

int n,t;
int M[N][N];
int c[N],d[N],f[N];

void dfs1(int);
void dfs(void);

int main(){
  int u,v;
  int i,j,k;
  scanf("%d", &n);

  for(i=0;i<n;i++){
    for(j = 0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0;j < k; j++){
      scanf("%d" , &v);
      v--;
      M[u][v] = 1;
    }
  }
  dfs();
  return 0;
}

void dfs1(int u){
  int i;
  c[u] = Y;
  d[u] =++t;
  for(i = 0;i < n;i++){
    if(M[u][i] == 0)continue;
    if(c[i] == X) dfs1(i);

  }
  c[u]=Z;
  f[u] =++t;
}
void dfs(void){
  int i;
  for(i = 0;i < n;i++){
    c[i] = X;
  }
  t= 0;
  for(i = 0; i < n; i++){
    if(c[i] == X)dfs1(i);
  }
  for(i = 0;i < n; i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
}
