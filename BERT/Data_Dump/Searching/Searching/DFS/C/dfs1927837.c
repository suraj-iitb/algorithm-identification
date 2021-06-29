#include<stdio.h>

#define N 101
#define W 1
#define G 2
#define B 3

int g[N][N], c[N], d[N], f[N], t = 0, n;

void visit(int);

int main(){
  int m, l, o, i, j, t;
  for( i = 0; i < N; i++){
    for( j = 0; j < N; j ++){

      g[i][j] = 0;

    }
  }

  scanf("%d", &n);
  
  for( i = 1; i <= n; i++){

    c[i] = W;

    scanf("%d%d", &m, &l);

    for( j = 1; j <= l; j++){

      scanf("%d", &o);  
      g[m][o] = W;

    }
  }

  for( i = 1; i <= n; i++){

    if( c[i] == W)
      visit( i);
    
    //printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  for( i = 1; i <= n; i++){
    
  printf("%d %d %d\n", i, d[i], f[i]);

  }
    
  return 0;
}

void visit(int x){
  int i;

  c[x] = G;
  d[x] = ++t;

  for( i = 1; i <= n; i++){

    if( g[x][i] == 0)continue;

    if(c[i] == W)      visit(i);
  }
  
  c[x] = B;
  f[x] = ++t;

}
