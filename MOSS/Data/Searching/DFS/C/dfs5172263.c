#include <stdio.h>

int n,P;
int G[100][100];
int A[100],B[100] = {0};

void dfs(int a) {
  int i,j,v;
  P++;  
  A[a] = P;
  for(v = 0 ; v < n ; v++) {
      if(G[a][v] == 1 && A[v] == 0 ) {
      dfs(v);
    }
  }
  P++;
  B[a] = P;
}



int main() {
  int i,j,k,l,u,a,t;
  for(i = 0 ; i < n ; i++){
      A[i] = 0;
  }
  scanf("%d",&n);

  for(i = 0 ; i < n + 1 ; i++){
    for(j = 0 ; j < n + 1 ; j++) {
      G[i][j] = 0;
    }
  }
  for(i = 0 ; i < n ; i++){
    scanf("%d %d ",&k,&u);
    for(j = 0 ; j < u ; j++) {
      scanf("%d",&a);
      G[k -1][a-1] = 1;
    }
  }
  for(i = 0 ; i < n ; i++) {
    if(A[i] == 0) 
    dfs (i);
  }
  for(i = 0 ; i < n ; i++) {
    printf("%d %d %d\n",i+1,A[i],B[i]);
  }
  return 0;
}
