#include<stdio.h>
#define N 100
#define GRAY 1
#define WHITE 0
#define BLACK 2

void dfs_visit(int );
void dfs();
void M_scan(int *);

int M[N][N];
int d[N],f[N],color[N];
int t,n;

int main(){

  M_scan(&n);
  dfs();

  return 0;
}

void dfs_visit(int u){
  int v;
  color[u]=GRAY;
  d[u]=++t;

  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;
    if(color[v]==WHITE) dfs_visit(v);
  }
  color[u]=BLACK;
  f[u]=++t;
}

void dfs(){
  int u=0;
  for(u=0;u<n;u++) color[u]=WHITE;
  t=0;
  for(u=0;u<n;u++){
    if(color[u]==WHITE) dfs_visit(u);
    }
  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}

void M_scan(int *n){
  int m,i,j;
  int nm,cn;
  int nn;
  scanf("%d",&(*n));
  nn=*n;
  for(i=0;i<nn;i++){
    for(j=0;j<nn;j++) M[i][j]=0;
  }
  for(i=0;i<nn;i++){
    scanf("%d %d",&nm,&m);
    for(j=0;j<m;j++){
      scanf("%d",&cn);
      M[nm-1][cn-1]=1;
    }
  } 
}

