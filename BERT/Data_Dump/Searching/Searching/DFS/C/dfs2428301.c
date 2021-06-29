#include<stdio.h>
#define BLACK 2
#define GRAY 1
#define WHITE 0
#define N 101
 
int color[N];
int n, G[N][N],f[N],d[N],time;
 
void visit(int u){
  int i; 
  color[u]=GRAY;
  d[u]= ++time;
  for(i=0; i<n; i++){
    if(G[u][i] == 1){
      if(color[i] == WHITE)visit(i);
    }
  }
 
  color[u]= BLACK;
  f[u]=++time;
}

int main(){
  int i,j,v,vnext,k;
  
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    color[i] = WHITE;
    for(j=0;j<n;j++) {
      G[i][j] = 0;
    }
  }
 
  for(i=0; i<n; i++){
    scanf("%d %d",&v,&k);
    for(j=0; j<k; j++){
      scanf("%d",&vnext);
      G[v-1][vnext-1] = 1; 
    }
  }
 
  for(i=0; i<n; i++){
    if(color[i]==WHITE) visit(i);
  }
 
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
