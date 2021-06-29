#include<stdio.h>

#define BLACK -1
#define GRAY  -2
#define WHITE -3

void DFSvisit(int);

int G[100][100],d[100],f[100],color[100];
int n,time;

void DFS(int n){
  int i;

  for(i=0;i<n;i++){
    if(color[i]==WHITE){
      DFSvisit(i);
    }
  }
}

void DFSvisit(int u){
  int i;

  color[u]=GRAY;
  time++;
  d[u]=time;

  for(i=0;i<=n;i++){
    if(G[u][i] && color[i]==WHITE){
      DFSvisit(i);
    }
  }
  color[u]=BLACK;
  f[u]=++time;
}

main(){
  int  i,j,k,m;

  scanf("%d",&n);

  for(i=0;i<100;i++){
    for(j=0;j<100;j++){
      G[i][j]=0;
    }
    color[i] = WHITE;
  }

  for(i=0;i<n;i++){ 
    scanf("%d%d",&j,&k);
    for(j=0;j<k;j++){
      scanf("%d",&m);
      G[i][m-1]=1;
    }
  } 
 
  DFS(n);

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
