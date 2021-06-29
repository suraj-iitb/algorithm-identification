#include<stdio.h>
#define W 1
#define G 2
#define B 3

int v[101][101], d[101], f[101], count = 1, color[101];

void visit(int u){
  int i;
  color[u] = G;
  d[u] = count++;

  for(i = 1; v[u][i] != 0; i++){
    if(color[v[u][i]] == W)
      visit(v[u][i]);
  }
  color[u] = B;
  f[u] = count++;
}

int main(){
  int n, i, j, u, k;

  scanf("%d", &n);

  for(i = 1; i < n + 1; i++){
    scanf("%d%d", &u, &k);
    for(j = 1; j < k + 1; j++){
      scanf("%d", &v[u][j]);
    }
  }

  for(i = 1; i <= n; i++)
    color[i] = W;
  for(i = 1; i <= n; i++){
    if(color[i] == W)
      visit(i);
  }

  for(i = 1; i < n + 1; i++)
    printf("%d %d %d\n", i, d[i], f[i]);

  return 0;
}

