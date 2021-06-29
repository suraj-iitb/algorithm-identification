#include<stdio.h>
#include<stdlib.h>

int table[100][100];
int d[100], f[100], flag[100], tt;

typedef struct{
  int u;
  int k;
  int *v;
}DATA;

void DFS_visit(int u, int n){
  int v;
  flag[u] = 1;
  d[u] = ++tt;
  for(v = 0; v < n; v++){
    if(table[u][v] == 0)continue;
    if(flag[v] == 0){
      DFS_visit(v, n);
    }
  }
  flag[u] = 2;
  f[u] = ++tt;
}

void DFS(int n){
  int u;
  for(u = 0; u < n; u++) flag[u] = 0;
  tt = 0;

  for(u = 0; u < n; u++){
    if(flag[u] == 0) DFS_visit(u, n);
  }
  for(u = 0;u < n; u++){
    printf("%d %d %d\n", u + 1, d[u], f[u]);
  }
}
  
int main(){
  int i, j, n, next;
  DATA a[100];

  scanf("%d", &n);
  if(n >= 1 && n <= 100){
    for(i=0;i<n;i++){
      d[i] = 0;
      f[i] = 0;
    }
    
    for(i = 0; i < n; i++){
      scanf("%d %d", &a[i].u, &a[i].k);
      a[i].u--;
      a[i].v = (int *)malloc(sizeof(int) * a[i].k);
      for(j = 0; j < a[i].k; j++){
	scanf("%d", &next);
	a[i].v[j] = next-1;
	table[a[i].u][next-1] = 1;
      }
    }
    
    DFS(n);
  }
  return 0;
}


