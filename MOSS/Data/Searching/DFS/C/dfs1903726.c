#include <stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int );

int G[N][N],d[N],f[N],color[N];
int time,n;


int main(){

  int u,v,k,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j] =0;

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){ 
      scanf("%d", &v);
      G[u-1][v-1]++;
    }
  }


  dfs();

  for(i=0;i<n;i++){
      printf("%d %d %d",i+1, d[i], f[i]);
    
    printf("\n");
  }

  return 0;
}

void dfs(){

  int i;

  for(i=0;i<n;i++){
    color[i] = WHITE;
    time = 0;

  }
  for(i=0;i<n;i++)
    if(color[i] == WHITE)
      visit(i);
}

void visit(int u){

  int i;

  color[u] = GRAY;
  time++;
  d[u] = time;

  for(i=0;i<n;i++)
    if(G[u][i]==1)
      if(color[i] == WHITE)
	visit(i);

  color[u] = BLACK;
  time++;
  f[u] = time;

}
