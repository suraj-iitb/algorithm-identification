#include<stdio.h>

#define W 3
#define G 1
#define B 2
#define MAX 101

int tim=1, A[MAX][MAX], col[MAX], d[MAX], f[MAX];

void Vis(int u){
  int i;
  col[u] = G;
  d[u] = tim++ ;

  for(i=1 ; A[u][i]!=0 ; i++){
    
    if(col[A[u][i]] == W)Vis(A[u][i]);
  }
  col[u] = B;
  f[u] = tim++;
}

void DFS(n){
  int i;
  for(i=1 ; i<=n ; i++)col[i] = W;
  
  for(i=1 ; i<=n ; i++)if(col[i] == W)Vis(i);
}

int main(){
  int n, u, k, v, i, j;

  scanf("%d",&n);

  for(i=1 ; i<=n ; i++){
    scanf("%d%d", &u, &k);
    A[u][k+1] = 0;
    for(j=1 ; j<=k ; j++){
      scanf("%d",&v);
      A[u][j] = v;
    }
  }

  DFS(n);

  for(i=1 ; i<=n ; i++)printf("%d %d %d\n", i, d[i], f[i]);

  
  return 0;
}

