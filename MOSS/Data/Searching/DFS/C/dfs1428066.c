#include<stdio.h>

int n, G[110][110], d[110], f[110], c[110];
int t = 0;

void visit(int u){

  int i, j, v;

  c[u] = 1;
  d[u] = ++t;
  
  for(i = 1; i <= n; i++)
    if(G[u][i] == 1 && c[i] == 0) visit(i);

  c[u] = 2;
  f[u] = ++t;
  
}

int main(){
   
  int i, j, k, u, v; 

  scanf("%d", &n);
  
  for(i = 1; i <= n; i++){
   c[i] = 0;
    for(j = 1; j <= n; j++){
      G[i][j] = 0;
    }
  }
  
  t = 0;

  for(i = 1; i <= n; i++){
    
    scanf("%d%d", &u, &k);
    
    for(j = 1; j <= k; j++){
      
      scanf("%d", &v);
      
      G[u][v] = 1;
    
    }
    
  }
  
  for(i = 1; i <= n; i++)
    if(c[i] == 0) visit(i);
  
  for(i = 1; i <= n; i++)
    printf("%d %d %d\n", i, d[i], f[i]);
  
  return 0;
  
}
