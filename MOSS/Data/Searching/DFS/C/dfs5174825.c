#include <stdio.h>

int n, time, c[100], d[100], f[100], Adj[100][100];

void visit(int u){
  int i;

  c[u]=1;
  d[u]=++time;

  for(i=0; i<n; i++){
    if(Adj[u][i]==0) continue;
    if(c[i]==0) visit(i);
  }

  c[u]=2;
  f[u]=++time;
}

int main(){
  int i, j, u, k, v;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      Adj[i][j]=0;
    }
  }

  for(i=0; i<n; i++){
    scanf("%d %d", &u, &k);

    for(j=0; j<k; j++){
      scanf("%d", &v);
      Adj[u-1][v-1]=1;
    }
  }

  for(i=0; i<n; i++) c[i]=0;
  time=0;

  for(i=0; i<n; i++){
    if(c[i]==0) visit(i);
  }

  for(i=1; i<=n; i++) printf("%d %d %d\n", i, d[i-1], f[i-1]);

  return 0;
}
