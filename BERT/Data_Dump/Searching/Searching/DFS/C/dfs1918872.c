#include<stdio.h>

#define N 101
#define WHITE  3
#define GRAY   4
#define BRACK  5

void DFSvisit(int);
void DFS();

int a[N][N],n,time=0,color[N],d[N],f[N],k[N];

int main(){
  int i,j,u,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k[i]);
    for(j=0;j<k[i];j++){
      scanf("%d",&v);
      a[u-1][j]=v-1;
    }
  }

  DFS();
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void DFSvisit(int u){
  int v;
  color[u]=GRAY;
  time++;
  d[u]=time;
  for(v=0;v<k[u];v++){
    if(a[u][v] && color[a[u][v]]==WHITE)
      DFSvisit(a[u][v]);
  }
  color[u]=BRACK;
  f[u]=++time;
}

void DFS(){
  int i;
  time=0;
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  for(i=0;i<n;i++){
    if(color[i]==WHITE) DFSvisit(i);
  }
}
