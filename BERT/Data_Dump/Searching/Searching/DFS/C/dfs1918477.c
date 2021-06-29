#include <stdio.h>

#define MAX 101
#define CORRECT 0
#define NOTCORRECT 1
#define YET 2
  
int n,d[MAX],f[MAX],g[MAX][MAX],cl[MAX],t=0;
  
void DFSV(int u){
  int v;
  cl[u] = YET;
  t++;
  d[u] = t;
  for(v=1; v<=n; v++){
    if((g[u][v] == 1)&& (cl[v] == CORRECT)){
      DFSV(v);
    }
  } 
  cl[u] = NOTCORRECT;
  f[u]= ++t;
}
  
int main(){
  int i,j,u,v,k;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      g[i][j] = 0;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      g[u][v] = 1;
    }
  }
  for(i=1;i<=n;i++){
    cl[i]=CORRECT;
  }
  for(i=1;i<=n;i++){
    if(cl[i]==CORRECT) DFSV(i);
  }
  for(i=1; i<=n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }  
  return 0;
}
