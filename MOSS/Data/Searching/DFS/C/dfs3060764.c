#include <stdio.h>
#define MAX 100
#define W 0
#define G 1
#define B 2

int n,A[MAX][MAX];
int c[MAX],d[MAX],f[MAX],e;

void cdf_v(int u){
  int v;
  c[u]=G;
  d[u]=++e;
  for(v=0;v<n;v++){
    if(A[u][v]==0)continue;
    if(c[v]==W){
      cdf_v(v);
    }
  }
  c[u]=B;
  f[u]=++e;
}

void cdf(){
  int u;
  for(u=0;u<n;u++)c[u]=W;

  e=0;

  for(u=0;u<n;u++){
    if(c[u]==W)cdf_v(u);
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main (){
  int x,y,z,i,j;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]==0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&x,&z);
    x--;
    for(j=0;j<z;j++){
      scanf("%d",&y);
      y--;
      A[x][y]=1;
    }
  }

  cdf();

  return 0;
}
  

