#include<stdio.h>
#define N 111
int G[N][N],X[N],Y[N],n;
void bfs(int,int);

int main(){
  int i, j, num;

  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    X[i] = 151210;
    scanf("%d",&num);
    scanf("%d",&Y[num]);

    for(j=1;j<=Y[num];j++) scanf("%d",&G[num][j]);
  }
  bfs(1, 0);
  for(i=1;i<=n;i++){
    if(X[i] == 151210) X[i] = -1;
  }
  for(i=1;i<=n;i++) printf("%d %d\n",i,X[i]);
  return 0;
}

void bfs(int x,int y){
  int i;
  X[x] = y;
  for(i = 1; i <= Y[x]; i++){
     if(y + 1 < X[G[x][i]]) bfs(G[x][i], y + 1);
  }
}
