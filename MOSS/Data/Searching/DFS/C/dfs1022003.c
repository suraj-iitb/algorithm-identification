#include <stdio.h>
#define BLK 1
#define WHI -1
#define GRY 0
#define N 101
 
int A[N][N];
int f[N],d[N];
int n,t=0,k;
int color[N];
 

void DFSV(int u){
  int v;
  
  color[u]=GRY;
  d[u] = ++t;
  
  for(v=1;v<=n;v++){
    if((color[v]==WHI) && (A[u][v]==1)){
      DFSV(v);
    }
  }
  color[u] = BLK;
  f[u]=++t;
}




void DFS(void){
    int u;
     
    for(u=1;u<=n;u++){
        color[u]=WHI;
        t=0;
    }
     
    for(u=1;u<=n;u++){
        if(color[u]==WHI)DFSV(u);
    }
     
}








int main(void){
    int ts,u,i,j;
     
    scanf("%d",&n);
     
    for(i=1;j<=n;i++){
        for(j=1;j<=n;j++){
            A[i][j]=0;
        }
    }
    


 
    for(i=1;i<=n;i++){
      scanf("%d%d",&u,&k);
            for(j=1;j<=k;j++){
                scanf("%d",&ts);
            A[i][ts] =1;
        }
    }




    DFS();
    for(i=1;i<=n;i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }
    return 0;
}
 
