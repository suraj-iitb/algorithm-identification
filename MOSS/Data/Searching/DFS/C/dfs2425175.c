#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
void dfs(void);
void visit(int);

int G[N][N],d[N],f[N],n,color[N],time;
int main(){

  int i,j,y,b,k;

  for(i=1;i<=100;i++){
    for(j=1;j<=100;j++){
      G[i][j]=0;
    }
  }
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d%d",&y,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&b);
      G[y][b]=1;
    }
  }

  dfs();

  for(i=1;i<=n;i++)
    printf("%d %d %d\n",i,d[i],f[i]);

  return 0;
}

void dfs(){
  int i;
  for(i=1;i<=n;i++)
    color[i]=WHITE;
  time=0;

  for(i=1;i<=n;i++){
    if(color[i]==WHITE)
      visit(i);
  }
}

void visit(int u){
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=1;i<=n;i++){
    if(G[u][i]!=0){
    if(color[i]==WHITE)
      visit(i);
    }}
  color[u]=BLACK;
  f[u]=++time;
}
