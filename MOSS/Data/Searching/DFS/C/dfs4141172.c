#include<stdio.h>
#define N 100
#define white 0
#define gray 1
#define black 2

void dfs_visit(int);
void dfs(void);

int a,G[N][N];
int color[N],b[N],c[N],t;

int main(){
  int x,k,i,j,v;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      G[i][j] = 0;
    }
  }
  for(i=0;i<a;i++){
    scanf("%d %d",&x,&k);
    x--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      G[x][v]=1;
    }
  }
  dfs();
  return 0;
}
void dfs_visit(int y){
  int v;
  color[y] = gray;
  b[y] = ++t;
  for(v=0;v<a;v++){
    if(G[y][v] == 0){
      continue;
    }
    if(color[v] == white){
      dfs_visit(v);
    }
  }
  color[y] = black;
  c[y]=++t;
}
void dfs(){
  int z;
  for(z=0;z<a;z++){
    color[z]=white;
  }
  t=0;
  for(z=0;z<a;z++){
    if( color[z] == white){
      dfs_visit(z);
    }
  }
  for(z=0;z<a;z++){
    printf("%d %d %d\n",z + 1,b[z],c[z]);
  }
}


