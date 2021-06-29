#include<stdio.h>

int P[101][101], f[101], d[101], Color[101];
int n, t=0;
void visit(int);

int main() {
  int i, j, x, y, z;
  scanf("%d",&n);
  for(i=0; i<101; i++)      Color[i]=0;
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      P[i][j] = 0;
    }
  }
  
  for(i=0; i<n; i++) {
    scanf("%d%d",&x, &y);
    for(j=0; j<y; j++) {
      scanf("%d", &z);
      P[x-1][z-1] = 1;
    }
  }
  for(i=0; i<n; i++)
    if(Color[i]==0)   visit(i); 
  for(i=0; i<n; i++)      printf("%d %d %d\n", i+1, d[i], f[i]);
  return 0;
}

void visit( int r) {
  int v;
  d[r] = ++t;
  Color[r] = 1;
  for(v=0; v<n; v++) {
    if(P[r][v] == 1 && Color[v] == 0)
      visit(v);
  }
  f[r] = ++t;
}

