#include <stdio.h>
#define N 100

int n,A[N][N],d[N],f[N]={0},t=0;
void visit(int);

int main(){
  int i,j,u,k,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    d[i]=0;
  }

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);

    for(j=0;j<k;j++){
      scanf("%d",&v);
      A[u-1][v-1] = 1;

    }
  }

  for(i=0;i<n;i++){
    if(d[i] == 0) visit(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}


void visit(int u){
  int i,j,v;
  t++;
  d[u] = t;
  for(v=0;v<n;v++){
    if(d[v] == 0 && A[u][v] == 1) visit(v);
  } 
  t++;
  f[u] = t;
}


