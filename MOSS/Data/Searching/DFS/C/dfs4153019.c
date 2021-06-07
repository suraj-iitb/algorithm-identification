#include <stdio.h>
int n,mg[105][105];
int d[105];
int t = 0;
int F[105] = {0};
int k = 0;

void visited(int u) {
  int i,j,v;
  t++;  
  d[u] = t;

  for(v=0;v<n;v++) {
    if(mg[u][v] == 1 && d[v] == 0 ) {
      visited(v);
    }
  }
  
  t++;
  F[u] = t;

}

int main() {
  int i,j,k,l,u,fg,t;

  for(i=0;i<n;i++) d[i] = 0;

  scanf("%d",&n);

  for(i=0;i<n+1;i++)
    for(j=0;j<n+1;j++) {
      mg[i][j] = 0;

    }

  for(i=0;i<n;i++){

    scanf("%d %d ",&k,&u);
    for(j=0;j<u;j++) {
      scanf("%d",&fg);
      mg[k -1][fg-1] = 1;
    }
  }
  for(i=0;i<n;i++) {
    if(d[i] == 0) 
    visited (i);
  }
    
  for(i=0;i<n;i++) {
    printf("%d %d %d\n",i+1,d[i],F[i]);
  }
  return 0;

    
    
}


