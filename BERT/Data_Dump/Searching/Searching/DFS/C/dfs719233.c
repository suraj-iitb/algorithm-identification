#include <stdio.h>

#define MAX 105
#define WHITE 0
#define BLACK 1
#define GRAY 2

int n,d[MAX],f[MAX],G[MAX][MAX],color[MAX],t=0;

void DFSVisit(int u){
  int v;
  
  color[u] = GRAY;
  t++;
  d[u] = t;
  
  for(v=1; v<=n; v++){
    if((G[u][v] == 1)&& (color[v] == WHITE)){
      DFSVisit(v);

    }
  }

  color[u] = BLACK;
  f[u]= ++t;
}

int main(){
  int i,j,u,v,k;
  
  scanf("%d",&n);

  /*array all 0*/
  for(i=1;i<= n; i++){
    for(j=1; j<= n; j++){
      G[i][j] = 0;
    }
  }

  for(i=1; i<= n; i++){
    scanf("%d%d",&u,&k);
    // u--;
    for(j=0; j<k; j++){
      scanf("%d",&v);
      // v--;
      G[u][v] = 1;
    }
  }

   for(i=1; i<=n; i++){
     color[i] = WHITE;
    }

   for(i=1; i<=n; i++){
     if(color[i] == WHITE) DFSVisit(i);
   }

  for(i=1; i<=n; i++){
    printf("%d ",i);
    printf("%d ",d[i]);
    printf("%d\n",f[i]);
  }
  
  return 0;
}
