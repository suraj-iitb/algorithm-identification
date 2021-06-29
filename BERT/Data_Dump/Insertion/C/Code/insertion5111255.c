#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, n;
  int *dat;

  // 入力
  scanf("%d", &n);
  dat = (int*)malloc(sizeof(int) * n);
  for (i = 0; i < n; ++i) scanf("%d", &dat[i]);


  for (i = 0; i < n; ++i) {
    int v = dat[i];
    int j = i - 1;

    while (j >= 0 && dat[j] > v) {
      dat[j+1] = dat[j];
      --j;
    }

    dat[j+1] = v;

    // 出力
    for (j = 0; j < n; ++j) {
      if (j) printf(" ");
      printf("%d", dat[j]);
    }
    putchar('\n');
  }

}

