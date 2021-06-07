#include<stdio.h>
#include<stdlib.h>
 
#define N 101
  
int color[N],time,d[N],f[N],e[N],v[N],A[N][N],B[N][N];
void DFS(int);
void DFEV(int);
int main(int argc, char *argv[]){
  int i,j,n,v1;
   
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      A[i][j]=0;
    }
  }
  
  scanf("%d",&n);
    
  for(i=1;i<=n;i++){
    scanf("%d%d",&v[i],&e[i]);
    for(j=1;j<=e[i];j++){
      scanf("%d",&v1);
      B[i][j]=v1;
      A[i][v1]= 1;
    }
  }
  DFS(n);
  
  return 0;
}

void DFS(int n){
  int i,u;
   
  for(i=1;i<=n;i++){
    u=v[i];
    color[u]=0;
    time=0;
  }
   
  for(i=1;i<=n;i++){
    u=v[i];
    if(color[u]==0){
      DFEV(u);
    }
    printf("%d %d %d\n",u,d[u],f[u]);
  }
}
void DFEV(int k){
  int v,i;
    
  color[k]=2;
  d[k]=++time;
  
  for(i=1;i<=e[k];i++){
    v=B[k][i];
    if(color[v]==0){
      DFEV(v);
    }
  }
  color[k]=1;
  f[k]=++time;
}
  
  
