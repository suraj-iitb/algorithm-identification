#include<stdio.h>
#define WHITE 0
#define BLACK 1
#define GRAY 2


int n,time;
int G[101][101];
int d[101];
int f[101];
int color[101];

void visit(int u){
  int i,j;
  color[u] = GRAY;
  d[u] = ++time;
  for(i=1;i<=n;i++){
    if(G[u][i] == 1){
      if(color[i] == WHITE)
	visit(i);
    }
  }
  color[u] = BLACK;
  f[u] = ++time;
};
    



void dfs(){
  int i;
  for(i=1;i<=n;i++){
    color[i] = WHITE;
  }
  time = 0;
  for(i=1;i<=n;i++){
    if( color[i] == WHITE)
      visit(i);
  }
};


int main(){
  int u,i,j,c,k;


  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&c);
    for(j=1;j<=c;j++){
      scanf("%d",&k);
      G[u][k] = 1;
    }
  }
  dfs();
 for(i=1;i<=n;i++)
   printf("%d %d %d\n",i,d[i],f[i]);


  return 0;
  
}

