#include <stdio.h>

#define MAX 100

int size[MAX], hval[MAX], roll[MAX][MAX];
void GVE(int c, int v);

int main(){
  int i, j, n, c;

  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    hval[i] = 10000;
    for(j = 1; j <= n; j++){
      roll[i][j] = 0;
    }
  }
  for (i = 1; i <= n; i++){
    scanf("%d", &c);
    scanf("%d", &size[c]);
    for(j = 1; j <= size[c]; j++){
      scanf("%d", &roll[c][j]);
    }
  }

  GVE(1, 0);

  for(i = 1; i <= n; i++){
    if(hval[i] == 10000){
      hval[i] = -1;
    }
    printf("%d %d\n", i, hval[i]);
  }
  return 0;
}

void GVE(int c, int v){
  int i;
  hval[c] = v;
  for (i = 1; i <= size[c]; i++){
    if (hval[roll[c][i]] > v){
      GVE(roll[c][i], v + 1);
    }
  }
}
