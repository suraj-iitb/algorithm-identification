#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

void dfs(void);
void visit(int);
int G[101][101];
int n,time,color[101],first[101],end[101];

void dfs(){
  int i;
  for(i=1;i<=n;i++)color[i]=WHITE;
  time=0;
  for(i=1;i<=n;i++){
    if(color[i]==WHITE)visit(i);
  }
}

void visit(int i){
  int j;
  color[i]=GRAY;
  first[i]=++time;
  for(j=1;j<=n;j++){
    if(G[i][j]==0)continue;
    if(color[j]==WHITE)visit(j);
  }
  color[i]=BLACK;
  end[i]=++time;
}
int main(){

  int i,j,k,l,m;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      G[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&k,&m);
    for(j=0;j<m;j++){
      scanf("%d",&l);
      G[k][l]=1;
    }
  }
  dfs();
  for(i=1;i<=n;i++)printf("%d %d %d\n",i,first[i],end[i]);
  return 0;
}
