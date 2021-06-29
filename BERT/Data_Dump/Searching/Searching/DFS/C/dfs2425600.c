#include <stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,V[MAX][MAX];
int color[MAX];
int time;
int d[MAX],f[MAX];

void Visit(int u){
  int v;

  color[u] = 1;
  d[u] = ++time;

  //  printf("time = %d\n",time);
  
  for(v=1;v<=n;v++){    
    if(V[u][v]==0)continue; //WHITE
    
    if(color[v]== 0){ //WHITE
      Visit(v);
    }
  }
  
  color[u] = 2; //BLACK
  f[u] = ++time;
};

void DFS(){
  int i;
  for(i=1;i<=n;i++){
    color[i] = 0; //WHITE
  }
  time = 0;
  
  for(i=1;i<=n;i++){
    if(color[i] == 0){ //WHITE
      Visit(i);     
    }
  }
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
};

int main(){
  int i,j;
  int id,k,v;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      V[i][j]=0;
    }
  }
    
  for(i=1;i<=n;i++){
    scanf("%d%d",&id,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&v);
      V[id][v]=1;
    }
  }

  DFS();

  return 0;
}
