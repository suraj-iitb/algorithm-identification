#include <stdio.h>
#define N 101

int g[N][N];
int d[N];
int t,n;
int f[N];

void visit(int u) {
  int i;
  t++;  
  d[u] =t;

  for(i=0;i<n;i++) {
    if(g[u][i] == 1 && d[i] == 0 ) {
      visit(i);
    }
  }
  t++;
  f[u] = t;
}

int main() {
  int i,j,k,m,x;

  for(i=0;i<n;i++) d[i] = 0;

  scanf("%d",&n);

  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++) {
      g[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d %d ",&k,&m);
    for(j=0;j<m;j++) {
      scanf("%d",&x);
      g[k-1][x-1]=1;
    }
  }
  
  for(i=0;i<n;i++) {
    if(d[i] == 0) 
      visit (i);
  }
    
  for(i=0;i<n;i++) {
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  
  return 0;
}

