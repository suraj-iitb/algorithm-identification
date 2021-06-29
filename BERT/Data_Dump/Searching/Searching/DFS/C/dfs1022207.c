#include<stdio.h>
#define WHITE 0    //non-visited
#define GRAY 1     //visited
#define BLACK 2    //finished
#define N 101

void DFS_Visit(int);

int n = 0;
int tt=0;
int color[N],d[N],f[N];
int A[N][N];

void DFS(void){
  int i;
  for(i=1 ; i<=n ; i++){
    color[i] = WHITE;
    tt = 0;
  }
  


  for(i=1 ; i<=n ; i++) if(color[i] == WHITE) DFS_Visit(i);
}

void DFS_Visit(int u){
  int i; 
  color[u] = GRAY;
  d[u] = ++tt;
  for(i=1 ; i<=n ; i++) if(color[i] == WHITE && A[u][i]) DFS_Visit(i);
  color[u] = BLACK;
  f[u] = ++tt;
}

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);


  for(i=1 ; i<=n ; i++){
    for(j=1 ; j<=n ; j++){
      A[i][j] = 0;
    }
  }

  for(i=1 ; i<=n ; i++){
    scanf("%d%d",&u,&k);
    for(j=1 ; j<=k ; j++){
      scanf("%d",&v);
      A[u][v] = 1;
    }
  }

  DFS();

  for(i=1 ; i<=n ; i++){
    printf("%d ",i);
    printf("%d ",d[i]);
    printf("%d\n",f[i]);
  }
  return 0;
}
