#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,t,b[MAX],e[MAX];
int A[MAX][MAX];
int color [MAX];

void dfs_init();
void dfs(int);

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      A[u][v]=1;
    }
  }

  dfs_init();
  
  return 0;
}

void dfs_init(){
  int i;
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }
  t=0;

  for(i=0;i<n;i++){
    if(color[i]==WHITE) dfs(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,b[i],e[i]);
  }
}

void dfs(int i){
  int j;
  color[i]=GRAY;
  b[i]=++t;
  for(j=0;j<n;j++){
    if(A[i][j]==0) continue;
    if(color[j]==WHITE) dfs(j);
  }
  color[i]=BLACK;
  e[i]=++t;
}
