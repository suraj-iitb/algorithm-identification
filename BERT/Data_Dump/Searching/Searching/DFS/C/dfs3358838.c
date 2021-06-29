#include <stdio.h>
#include <stdlib.h>

#define N 101

int a[N][N], b[N], c[N], t=0, n;

void DFS(int p);

int main(void){
  int i, j;
  int u, k, v;
  
  scanf("%d",&n);
  if(n<1 || n>N) exit(1);

  for(i=1;i<=n;i++){
    b[i]=0;
    c[i]=0;
  }
  
  for(i=1; i<=n; i++)
    for(j=1;j<=n;j++) a[i][j]=0;
  
  for(i=0;i<n;i++){
    scanf("%d %d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      a[u][v]=1;
    }
  }
  
  for(i=1; i<=n; i++){
    DFS(i);
  }
  for(i=1; i<=n; i++) printf("%d %d %d\n",i,b[i],c[i]);
  
  return 0;
}


void DFS(int r){
  int i;
  
  if(b[r]==0){
    t++;
    b[r]=t;
    for(i=1; i<=n; i++){
      if(a[r][i]==1) DFS(i);
    }
    t++;
    c[r]=t;
  }

  return ;
}
  

