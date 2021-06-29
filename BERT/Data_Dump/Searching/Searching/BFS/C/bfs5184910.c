#include<stdio.h>

int matrix[101][101];
int level[101];
int queue[101];

int main(){
  int n, i, j, u, v, k;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d%d", &u, &k);
    for(j=0; j<k; j++){
      scanf("%d", &v);
      matrix[u][v] = 1;
    }
  }

  for(i=1; i<=n; i++) level[i]=-1;

  int qHead=0, qTail=0;
  queue[qTail++] = 1;
  level[1] = 0;

  while(qHead!=qTail){
    int v=queue[qHead++];
    for(i=1; i<=n; i++){
      if(level[i]==-1 && matrix[v][i]==1){
        level[i] = level[v]+1;
        queue[qTail++] = i;
      }
    }
  }

  for(i=1; i<=n; i++) printf("%d %d\n", i, level[i]);

  return 0;
}
