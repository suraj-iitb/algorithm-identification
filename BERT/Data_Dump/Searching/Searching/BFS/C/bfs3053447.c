#include <stdio.h>
#define NIL -1
#define MAX 100
int s[MAX], h[MAX], r[MAX][MAX];
void G(int c, int v);
int main(){
  int i, j, n, c;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    h[i] = 10000;
    for(j = 1; j <= n; j++){
      r[i][j] = 0;
    }
  }
  for (i = 1; i <= n; i++){
    scanf("%d", &c);
    scanf("%d", &s[c]);
    for(j = 1; j <= s[c]; j++){
      scanf("%d", &r[c][j]);
    }
  }
  G(1, 0);
  for(i = 1; i <= n; i++){
    if(h[i] == 10000){
      h[i] = NIL;
    }
    printf("%d %d", i, h[i]);
    puts("");
  }
  return 0;
}
void G(int c, int v){
  int i;
  h[c] = v;
  for (i = 1; i <= s[c]; i++){
    if (h[r[c][i]] > v){
      G(r[c][i], v + 1);
    }
  }
}

