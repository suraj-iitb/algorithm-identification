#include<stdio.h> 


int n, M[1000][1000], color[1000], d[1000], f[1000], tt=0;

void dfs_visit(int u) {
  
  int v;
  
  color[u] = 1;
  
  tt++;
  
  d[u] = tt;
  
  for ( v = 0; v < n; v++ ) {
    if ( M[u][v] == 0 ) {
      continue;
    }
    if ( color [v] == 0 ) {
      dfs_visit(v);
    }
  }
  
  f[u] = ++tt;

  return;
  
}

void print(int a,int *b,int *c){

  printf("%d",a);
  printf(" %d", b[a-1]);
  printf(" %d", c[a-1]);
  printf("\n");

  return;

}

void dfs() {
  int i;
  
  for ( i = 0; i < n; i++ ) color[i] = 0;

  dfs_visit(0);
  
  for ( i = 1; i < n; i++ ) {  
    if ( color[i] == 0 ) dfs_visit(i);
    else continue;
  }
	
  for ( i = 1; i<=n; i++ ) {
    print(i,d,f);
  }

  return;
}

int main() {
  int u, v, k, i, j;
      
  scanf("%d", &n);
  
  for (i = 0; i<n; i++ ) {
    for (j = 0; j<n; j++ ) M[i][j] = 0;
  }
  
  for (i = 0; i < n; i++ ) {
    scanf("%d %d", &u, &k);

    
    for (j = 0; j < k; j++ ) {
      scanf("%d", &v);
      v--;
      M[u-1][v] = 1;
    }
  }
  
  dfs();
  
  return 0;
}

