#include<stdio.h>

#define N 100 
#define BLACK 1
#define GRAY  2
#define WHITE 3
 
int G[N][N],d[N],f[N],color[N];
int n,time;

 void visit(int r){
  int v;
 
  color[r]=GRAY;
  time++;
  d[r]=time;
 
  for(v=0;v<=n;v++){
    if(G[r][v] && color[v]==WHITE){
      visit(v);
    }
  }
  color[r]=BLACK;
  f[r]=++time;
 }

void dfs(int n){
  int u;
  
  for(u=0;u<n;u++){
    if(color[u]==WHITE){
      visit(u);
    }
  }
}

int main(void){
  
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
  
  dfs(n);
 
  for(i=0;i<n;i++)
    printf("%d %d %d\n",i+1,d[i],f[i]);
  
  return 0;
}
