#include<stdio.h>

#define N 101
#define WHITE  0
#define GRAY   1
#define BRACK  2

void DFS();
void visit(int);

int n,time=0,color[N],d[N],f[N],k[N],G[N][N];

int main(){

  int i,j,u,v;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k[i]);
    for(j=0;j<k[i];j++){
      scanf("%d",&v);
      G[u-1][j]=v-1;
    }
  }

  DFS();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}

void DFS(){
  int i;

  for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  for(i=0;i<n;i++){
    if(color[i]==WHITE) visit(i);
  }
}


void visit(int u){
  int v;

  color[u]=GRAY;
  time++;
  d[u]=time;
  
  for(v=0;v<k[u];v++){
    if(G[u][v] && color[G[u][v]]==WHITE)
      visit(G[u][v]);
  }
  
  color[u]=BRACK;
  f[u]=++time;
}
