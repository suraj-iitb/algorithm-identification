#include <stdio.h>
#define MAX 101

void serch(int);
int n, M[MAX][MAX], c[MAX], d[MAX], f[MAX], time;

int main(){
  int i, j, m, r, p;
  time = 0;

  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      M[i][j] = 0;
    }
  }
  for(i = 1; i <= n; i++){
    c[i] = 0;
  }
  for(i = 1; i <= n; i++){
    scanf("%d%d",&m,&r);
    for(j = 1; j <= r; j++){
      scanf("%d",&p);
      M[i][p] = 1;
    }
  }

  for(i = 1; i <= n; i++){
    if(c[i] == 0) serch(i);
  }
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

void serch(int a){
  int i;
  c[a] = 1;
  ++time;
  d[a] = time;

  for(i = 1; i <= n; i++){
    if(M[a][i] == 0) continue;
    if(c[i] == 0){
      serch(i);
    }
  }
  c[a] = 2;
  time++;
  f[a] = time;
  return;
}

