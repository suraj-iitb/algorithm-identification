#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,A[100][100],color[100],d[100],f[100],time;

void visit(int u){
  int i;
  color[u]=GRAY;
  d[u]=++time;
  for(i=0;i<n;i++){
    if(A[u][i]==0)continue;
    if(color[i]==WHITE)visit(i);
  }
  color[i]=BLACK;
  f[u]=++time;
}

void dfs(){
  int i;
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  time=0;

  for(i=0;i<n;i++){
    if(color[i]==WHITE)visit(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

}

int main(){

  int i,j,k,l,h;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&k,&l);
    for(j=0;j<l;j++){
      scanf("%d",&h);
      A[k-1][h-1]=1;
    }
  }

  dfs();
  return 0;
}

