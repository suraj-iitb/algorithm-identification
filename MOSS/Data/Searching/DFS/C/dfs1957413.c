
#include <stdio.h>
#define N 100
#define WHITE 1
#define GRAY 2
#define BLACK 3

int d[N],f[N],time,S[N],G[N][N],n;


void DFSvisit(int);
void DFS(void);




int main(){
  int i,j,u,v,k;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      G[i][j]=0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u-1][v-1]=1;
    }
  }

  DFS();

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}







void DFSvisit(int u){
  int i;

  S[u]=GRAY;
  d[u]=++time;

  for(i=0;i<n;i++){
    if(G[u][i]==1 && S[i]==WHITE){
      DFSvisit(i);
    }
  }

  S[u]=BLACK;
  f[u]=++time;
}





void DFS(void){
  int i;
  
  for(i=0;i<n;i++){
    S[i]=WHITE;
  }
  time=0;
  for(i=0;i<n;i++){
    if(S[i]==WHITE){
      DFSvisit(i);
    }
  }
}
