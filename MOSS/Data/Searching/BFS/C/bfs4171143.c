#include <stdio.h>
#define N 100
#define MAX 100000000

int a[N+1][N+1], b[N+1], n, size[N+1];

void kansu(int p, int t){
  int i;
  b[p] = t;
  for(i=1;i<=size[p];i++) if(t + 1 < b[a[p][i]]) kansu(a[p][i], t + 1);
}

int main(){
  int i, j, u;
  scanf("%d", &n);
  for(i=1;i<=n;i++){
    b[i] = MAX;
    scanf("%d", &u);
    scanf("%d", &size[u]);
    for(j=1;j<=size[u];j++) scanf("%d", &a[u][j]);
  }
  kansu(1, 0);
  for(i=1;i<=n;i++) printf("%d %d\n", i, (b[i] == MAX) ? -1 : b[i]);
  return 0;
}

