#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
int M[N][N];
int n;
int color[N],d[N],f[N],tt;
void dfs_v(int u/* arguments */) {
  /* code */
  int v;
  color[u]=GRAY;
  d[u]=++tt;
  for (v = 0; v < n; v++) {
    /* code */
    if(M[u][v]==WHITE){
      continue;
    }
    if(color[v]==WHITE){
      dfs_v(v);
    }
  }
  color[u]=BLACK;
  f[u]=++tt;
}
void dfs(){
  int u;
  for(u=0;u<n;u++){
    color[u]=WHITE;
  }
  tt=0;
  for(u=0;u<n;u++){
    if (color[u]==WHITE/* condition */) {
      /* code */
      dfs_v(u);
    }
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}


int main(){
  int i, j, u, k, v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for (j = 0; j < n; j++) {
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
  for(j=0;j<k;j++){
    scanf("%d", &v);
    v--;
    M[u][v]=1;
    }
  }

  dfs();

  /*for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(j!=0){
        printf(" ");
      }
      printf("%d",M[i][j]);
    }
    printf("\n");
  }*/
  return 0;
}

