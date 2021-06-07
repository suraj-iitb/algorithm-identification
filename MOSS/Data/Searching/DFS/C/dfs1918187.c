#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void Dfs(void);
void Dfsvisit(int);


int n,time;
int d[N+1],f[N+1],G[N+1][N+1],C[N+1];

int main(){

  int i,j,k,id,l;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      G[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d %d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&l);
      G[i][l]=1;
    }
  }

  Dfs();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

void Dfs(void){
 
  int i;

  for(i=1;i<=n;i++){
    C[i]=WHITE;
  }
  time=0;
  for(i=1;i<=n;i++){
    if(C[i]==WHITE){
      Dfsvisit(i);
    }
  }
}

void Dfsvisit(int u){

  int v;

  C[u]=GRAY;
  d[u]=++time;

  for(v=1;v<=n;v++){
    if(G[u][v]==1){
      if(C[v]==WHITE){
	Dfsvisit(v);
      }
    }
  }

  C[u]=BLACK;
  f[u]=++time;
}
