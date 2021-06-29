#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,ary[N][N];
int color[N],pary[N],eary[N],time;

void dfs(int i){
  int j;
  color[i]=GRAY;
  pary[i]=++time;
  for(j=0;j<n;j++){
    if(ary[i][j]==0)continue;
    if(color[j]==WHITE){
      dfs(j);
    }
  }
  color[i]=BLACK;
  eary[i]=++time;
}

void dfs_init(){
  int i;
  for(i=0;i<n;i++){
    color[i]=WHITE;    
  }
  time=0;
  for(i=0;i<n;i++){
    if(color[i]==WHITE)dfs(i);
  }
}

int main(){
  int i,j,k,u,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      ary[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      ary[u][v]=1;
    }
  }
  dfs_init();
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,pary[i],eary[i]);
  }
  return 0;
}
  

