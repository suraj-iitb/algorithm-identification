#include<stdio.h>
#define N 100
#define W 0
#define G 1
#define B 2

int n,K[N][N];
int col[N],d[N],f[N],t;

void dfs_vis(int u){
  int v;
  col[u] = G;
  d[u] = ++t;
  for (v=0;v<n;v++){
    if (K[u][v] == 0)continue;
    if (col[v] == W) {
      dfs_vis(v);
    }
  }
  col[u] = B;
  f[u] =  ++t;

}

void dfs(){
  int u;
  for(u=0;u<n;u++)col[u]=W;
  t = 0;

  for(u=0;u<n;u++){
    if (col[u] == W) dfs_vis(u);
  }

  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}


int main(){
  int u,v,k,i,j,q,x=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
   for (j=0;j<n;j++) K[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      K[u][v] = 1;
    }
  }
  dfs();

  for(q=1;q<5;q++){
    x += q;
  }



  return 0;

}

