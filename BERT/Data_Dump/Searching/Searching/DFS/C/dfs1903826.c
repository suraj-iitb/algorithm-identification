#include<stdio.h>
#define MAX 102
#define WHITE -1
#define BLACK -2
#define GRAY -3

int n,time=0;
int M[MAX][MAX];
int d[MAX],f[MAX],color[MAX];

void visit(int u){
  int v;
  color[u] = GRAY;
  d[u] = ++time;
  for( v  = 0 ; v < n ; v++ ){
    if( color[v] == WHITE && M[u][v] == 1)
      visit(v);
  }
  color[u] = BLACK;
  f[u] = ++time;
}

void dfs(){
  int u;
  for( u = 0 ; u < n ; u++ )
    {
      color[u] = WHITE;
      d[u] = 0;
      f[u] = 0;
    }
  time = 0;
  for( u = 0 ; u < n ; u++ ){
    if( color[u] == WHITE )
      visit(u);
  }
}

int main(){
  int i,j,x,num1,num2;
  
  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    for( j = 0 ; j < n ; j++ )
      M[i][j] = 0;
  }
    

  for( i = 0 ; i < n ; i++ ){
    scanf("%d%d",&num1,&x);
    for( j = 0 ; j < x ; j++ ){
      scanf("%d",&num2);
      M[num1-1][num2-1] = 1;
    }
  }
  
  dfs();

  for( i = 0 ; i < n ; i++ )
    printf("%d %d %d\n",i+1,d[i],f[i]);
  
  return 0;
}
