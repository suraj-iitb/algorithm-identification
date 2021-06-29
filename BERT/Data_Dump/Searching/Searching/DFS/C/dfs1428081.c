#include <stdio.h>
#define N 1000
#define WHITE 0
#define BLACK 1
#define GRAY 2

int A[N][N],color[N],d[N],f[N],k[N];
int n,u,time;


void visit(int r){

  int i;

  color[r] = GRAY;
  d[r] = ++time;
  for(i=1;i<=k[r];i++){
    if(color[A[r][i]] == WHITE){
      visit(A[r][i]);
    }
  }
  color[r] = BLACK;
  f[r] = ++time;
}

void dfs(void){
  
  int i;
  
  for(i=1;i<=n;i++){
    color[i] = WHITE;
  }
  time = 0;
  for(i=1;i<=n;i++){
    if(color[i] == WHITE){
      visit(i);
    }
  }
}


int main(void){

  int i,j;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k[i]);
    for(j=1;j<=k[i];j++){
      scanf("%d",&A[i][j]);
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
