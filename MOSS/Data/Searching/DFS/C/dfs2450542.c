#include <stdio.h>
#define N 1000

int t,n,d[N],f[N],M[N][N] = {};
char c[N];

void visit(int);
void depth();

int main(){
  int a,b,c,i,j;
  
  scanf("%d", &n);
  for (i=1;i<=n;i++) {
    scanf("%d%d",&a,&b);
    for (j=1;j<=b;j++) {
      scanf("%d",&c);
      M[a][c] = 1;
    }
  }
  
  depth();
  
  for (i=1;i<=n;i++) {
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  return 0;
}

void visit(int a){
  int i;
  
  c[a] = 'G';
  d[a] = ++t;
  for (i=1;i<=n;i++) {
    if (M[a][i] == 1 && c[i] == 'W') {
      visit(i);
    }
  }
  c[a] = 'B';
  f[a] = ++t;
}
  
void depth(){
  int i;
  for (i=1;i<=n;i++) c[i] = 'W';
  t = 0;
  for (i=1;i<=n;i++) if (c[i] == 'W') visit(i);
}
