#include<stdio.h>
#define MAX 100

int n;
int list[MAX+1][MAX+1];
int c[MAX+1],d[MAX+1],f[MAX+1],time;
int u,v,k;

void dfs_visit(int u) {
  int i;
  c[u] = 1;
  d[u] = ++time; 
  for ( i = 1; i <= n; i++) {
    if (list[u][i] == 0) continue;
    if (c[i] == 0) {
      dfs_visit(i);
    }
  }
  c[u] = 2;
  f[u] = ++time; 
}
 
void dfs() {
 
  int i;
  for (i = 1; i <= n; i++) {
    c[i] = 0;
  }
  time = 0;
 
  for (i = 1; i <=n; i++) {
    if (c[i] == 0) {
      dfs_visit(i);
    }
  }
 
  for (i = 1; i <= n; i++) {
    printf("%d %d %d\n", i, d[i], f[i]);
  }
}
 

int main(){
  int i,j;

  scanf("%d",&n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      list[i][j] = 0;
    }
  }
   
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &u, &k);
    
    for (j = 1; j <= k; j++) {
      scanf("%d", &v);
      
      list[u][v] = 1;
    }
  }
  dfs();

  return 0;
}

