#include <stdio.h>

#define N 100

#define WHITE 0
#define BLACK 1
#define GRAY 2

int n,M[N][N];

int color[N],d[N],f[N],tt;

void DFS_visit(int u){ /*再帰関数による深さ優先探索*/
  int v;
  color[u]=GRAY;
  d[u]=++tt; /*最初の訪問*/

  for(v=0;v<n;v++){
    if(M[u][v]==0) continue;

    if(color[v]==WHITE){
      DFS_visit(v);
    }
  }
  color[u] = BLACK;
  f[u]=++tt; /*訪問終了*/
}

void DFS(){
  int u;
  for(u=0;u<n;u++){
    color[u]=WHITE;
    tt=0;
  }

  for(u=0;u<n;u++){/* 未訪問のuを始点として深さ優先探索 */
    if(color[u]==WHITE) DFS_visit(u);
  }

  for(u=0;u<n;u++){
    printf("%d %d %d\n",u+1,d[u],f[u]);
  }
}

int main(){
  int i,j,u,v,k;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;

  for(j=0;j<k;j++){
    scanf("%d",&v);
    v--;
    M[u][v]=1;
  }
}
DFS();

return 0;
}
    

