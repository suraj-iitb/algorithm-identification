#include <stdio.h>
#define A 100
#define B 0
#define C 1
#define D 2

int n, a[A][A];
int c[A],d[A],b[A],t;

void dfs_visit(int u){
  int v;
  c[u] = C;
  d[u] = ++t;
  for(v = 0 ; v < n ; v++){
    if(a[u][v] == 0) continue;
    if(c[v] == B){
      dfs_visit(v);
    }
  }
  c[u] = D;
  b[u] = ++t;
}

void dfs(){
  int u;
  for(u = 0 ; u < n ; u++){
    if(c[u] == B) dfs_visit(u);
  }
  for(u = 0 ; u < n ; u++){
    printf("%d %d %d\n",u+1,d[u],b[u]);
  }
}

int main(){
  int u,v,k,i,j;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    for(j = 0 ; j < n ; j++){
      a[i][j]=0;
    }
  }

 for(i = 0 ; i < n ; i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      v--;
      a[u][v] = 1;
    }
  }

  dfs();

  return 0;
}
