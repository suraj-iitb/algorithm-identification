#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs();
void visit(int);

int num,array[N][N];
int color[N],data[N],f[N],count;

void visit(int u){
  int v;
  color[u]=GRAY;
  data[u]=++count;
  for(v=0;v<num;v++){
    if(array[u][v]==0)continue;
    if(color[v]==WHITE){
      visit(v);
    }
  }
  color[u]=BLACK;
  f[u]=++count;
}

void dfs(){
  int u;
  for(u = 0;u < num;u++){
    color[u] = WHITE;
  }
  count = 0;

  for(u = 0;u < num;u++){
    if(color[u] == WHITE){
      visit(u);
    }
  }
  for(u = 0;u < num;u++){
    printf("%d %d %d\n",u + 1,data[u],f[u]);
  }
}

int main(){
  int u,v,k,i,j;

  scanf("%d",&num);
  for(i=0; i<num; i++){
    for(j=0; j<num; j++)array[i][j]=0;
  }

  for(i=0; i<num; i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      array[u][v]=1;
    }
  }

  dfs();

  return 0;
}
