#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define W -1
#define G -2
#define B -3

void DFS();
void visit(int);

int n,t;
int d[MAX],f[MAX],color[MAX];
int A[MAX][MAX];

int main(){
  int i,j,u,v,k;

  scanf("%d",&n);

 for(i=1 ; i<=n ; i++){
    for(j=1 ; j<=n ; j++){
      A[i][j]=0;
    }
  }

  for(i=0 ; i<n ; i++){
    scanf("%d %d",&u,&k);
    for(j=0 ; j<k ; j++){
      scanf("%d",&v);
      A[u][v]=1;
    }
  } 

  DFS();
  
  for(i=1 ; i<=n ; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  return 0;
}

void DFS(){
  int i;
  for(i=1 ; i<=n ;i++){
    color[i]=W;
  }
  t = 0;
  for(i=1 ; i<=n ;i++){
    if(color[i]==W){
      visit(i);
    }
  }
}

void visit(int u){
  int i;

  color[u] = G;
  d[u] = ++t;

  for(i=1 ; i<=n ; i++){
    if(A[u][i]==0)continue;
    if(color[i]==W)visit(i);
  }
  color[u] = B;
  f[u] = ++t;
}
