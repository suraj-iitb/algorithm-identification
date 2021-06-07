#include<stdio.h>
#define WHITE 2
#define GRAY 1
#define BLACK 0

int d[101],f[101],color[101],m,time;
int mat[101][101] = {{0}};

void visit(int u){
  int i;
  color[u] = GRAY;
  d[u] = ++time;
  for(i = 1; i <= m; i++){
    if(mat[u][i] == 1 && color[i] == WHITE) visit(i);
  }
  color[u] = BLACK;
  f[u] = ++time;
}


void dfs(void){
  int i;
  for(i = 1; i <= m; i++) color[i] = WHITE;
  time = 0;
  for(i = 1; i <= m; i++){
    if(color[i] == WHITE) visit(i);
  }
}


int main(){
  int next[100][100];
  int k,num,i,j;

  scanf("%d",&m);

  for(i = 1; i <= m; i++){
    scanf("%d %d",&num,&k);
    for(j = 1 ; j <= k; j++){
      scanf(" %d",&next[i][j]);
      mat[i][next[i][j]] = 1;
    }
  }
  

  dfs();

  for(i = 1; i <= m; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  } 
 
  return 0;
}

