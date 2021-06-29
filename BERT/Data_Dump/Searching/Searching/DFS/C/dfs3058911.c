#include <stdio.h>
#define N 100

int A[N+1][N+1], s[N+1], b[N+1], c[N+1], n, t;

void d(int p){
  int i;
  
  b[p] = t++;
  
  for(i=1;i<=s[p];i++) if(!b[A[p][i]]) d(A[p][i]);
  c[p] = t++;
}

int main(){
  int i, j, u, v;
  
  scanf("%d", &n);
  t = 1;
  
  for(i=1;i<=n;i++){
    b[i] = c[i] = 0;
    scanf("%d", &u);
    scanf("%d", &s[u]);
    
    for(j=1;j<=s[u];j++) scanf("%d", &A[u][j]);
  }
  
  for(i=1;i<=n;i++) if(!b[i]) d(i);
  for(i=1;i<=n;i++) printf("%d %d %d\n", i, b[i], c[i]);

  
  return 0;
}

