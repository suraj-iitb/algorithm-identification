#include<stdio.h>
#define MAX 101
#define WHITE -1
#define GRAY -2
#define BLACK -3

int G[MAX][MAX],d[MAX],f[MAX],color[MAX];
int n,k[MAX],u,v,time;
void DFSvisit(int u){
  int i;

  color[u] = GRAY;
  time++;
  d[u] = time;


  for(i=1; i<=k[u]; i++){
    // printf("u = %d %d now -> %d\n",uu,k[uu],vv);
    if(color[G[u][i]] == WHITE) {
      //printf("%d\n",G[uu][i]);
      DFSvisit(G[u][i]);
    }
  }
  //printf("%d finished!\n",u);
  color[u] = BLACK;
  f[u] = ++time;
  //printf("f = %d\n",f[u]);
}


void DFS(){

  for(u=1; u<=n; u++){
    color[u] = WHITE;
  }
  time = 0;
  for(u=1; u<=n; u++){
 
    if(color[u]==WHITE) {
      // printf("u = %d\n",u);
      DFSvisit(u);
    }
  }
}


int main(){
  int i,j;

  scanf("%d",&n);

  for(i=1; i<=n; i++){
    scanf("%d%d",&u,&k[i]);
    for(j=1; j<=k[i]; j++){
      scanf("%d",&G[i][j]);
    }
  } 
  DFS();

  for(i=1; i<=n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}
