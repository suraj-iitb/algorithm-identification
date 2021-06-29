#include <stdio.h>
#define N 100

int a[N+1][N+1], b[N+1], c[N+1], d[N+1], n, t;

void kansu(int x){
  int i;
  c[x] = t++;
  for(i=1;i<=b[x];i++) if(!c[a[x][i]]) kansu(a[x][i]);
  d[x] = t++;
}

int main(){
  int i, j, r, v;
  scanf("%d", &n);
  t=1;
  for(i=1;i<=n;i++){
    c[i] = d[i] = 0;
    scanf("%d", &r);
    scanf("%d", &b[r]);
    for(j=1;j<=b[r];j++) scanf("%d", &a[r][j]);
  }
  for(i=1;i<=n;i++) if(!c[i]) kansu(i);
  for(i=1;i<=n;i++) printf("%d %d %d\n", i, c[i], d[i]);
  return 0;
}

