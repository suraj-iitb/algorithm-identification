#include <stdio.h>
#define N 120
#define GRAY 99
#define WHITE 100
#define BLACK 101


void DFS(void);
void DFS_visit(int);


int n,u,k,d[N],f[N],t,color[N],G[N][N];

main(){

  int i,j,v;

  scanf("%d",&n);

  for(i=1; i<=n; i++){

    scanf("%d%d",&u,&k);

    for(j=1; j<=k; j++){

      scanf("%d",&v);

      G[i][v]=1;

    }

  }

  DFS();

  for(i=1; i<=n; i++)
 printf("%d %d %d\n",i,d[i],f[i]);
   

  return 0; 

}

void DFS(void){

  int i;

  for(i=1; i<=n; i++){
    color[i]=WHITE;
    t=0;
  }
  
  for(i=1; i<=n; i++){
    if(color[i]==WHITE)
      DFS_visit(i);
    
  }

}



void DFS_visit(int u2){

  int i;

  color[u2]=GRAY;

  d[u2]=++t;

  for(i=1; i<=n; i++){

    if(G[u2][i]==1 && color[i]==WHITE)
      DFS_visit(i);
  }

  color[u2]=BLACK;

  f[u2]=++t;

}
