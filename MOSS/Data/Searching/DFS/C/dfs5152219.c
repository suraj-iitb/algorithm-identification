#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n,m[N][N];
int c[N],d[N],f[N],g;

void dfs_visit(int u){
  int v;
  c[u]=GRAY;
  d[u]=++g;
  for(v=0;v<n;v++){
    if(m[u][v]==0){
        continue;
    }
    if(c[v]==WHITE){
      dfs_visit(v);
    }
  }
  c[u]=BLACK;
  f[u]=++g;
}

void dfs(){
  int u;
  for(u=0;u<n;u++){
      c[u]=WHITE;
  }
  g=0;

  for(u=0;u<n;u++){
    if(c[u]==WHITE){
        dfs_visit(u);
    }
  }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int a,b,c,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        m[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    a--;
    for(j=0;j<b;j++){
      scanf("%d",&c);
      c--;
      m[a][c]=1;
    }
  }
  dfs();
  return 0;
}

