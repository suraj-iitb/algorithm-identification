#include<stdio.h>
 
#define N 100
 
void visit(int);
 
int color[N][N], d[N], f[N];
int n, t = 0;
 
int main() {
  int i, j, u, k, a;
 
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d%d", &u, &k);
    
    for(j = 0; j < k; j++) {
      scanf("%d",&a);
      color[u - 1][a - 1] = 1;
    }
  }
 
  for(i = 0; i < n; i++) {
    if(d[i] == 0) {
      visit(i);
    }
  }
 
    for(i = 0; i < n; i++) {
      printf("%d %d %d\n", i + 1, d[i], f[i]);
    }
 
    return 0;
}
 
void visit(int x) {
  int i;
  t++;
  d[x] = t;
 
  for(i = 0; i < n; i++) {
    if(color[x][i] != 0 && d[i] == 0) {
      visit(i);
    }
  }
 
  t++;
  f[x] = t;
}

