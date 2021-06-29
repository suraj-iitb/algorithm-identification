#include <stdio.h>
 
#define MAX 1000
#define WHITE 0
#define BLACK 1
#define GRAY 2
 
int n,d[MAX],f[MAX],g[MAX][MAX],cl[MAX],t=0;
 
void DFSV(int u){
  int v;
   
  cl[u] = GRAY;
  t++;
  d[u] = t;
   
  for(v=1; v<=n; v++){
    if((g[u][v] == 1)&& (cl[v] == WHITE)){
      DFSV(v);
 
    }
  } 
  cl[u] = BLACK;
  f[u]= ++t;
}
 
int main(){
  int i,j,u,v,k;
   
  scanf("%d",&n);
 
  for(i=1;i<= n; i++){
    for(j=1; j<= n; j++){
      g[i][j] = 0;
    }
  }
 
  for(i=1; i<= n; i++){
    scanf("%d%d",&u,&k);

    for(j=0; j<k; j++){
      scanf("%d",&v);

      g[u][v] = 1;
    }
  }
 
   for(i=1; i<=n; i++){
     cl[i] = WHITE;
    }
 
   for(i=1; i<=n; i++){
     if(cl[i] == WHITE) DFSV(i);
   }
 
  for(i=1; i<=n; i++){
    printf("%d ",i);
    printf("%d ",d[i]);
    printf("%d\n",f[i]);
  }
   
  return 0;
}
