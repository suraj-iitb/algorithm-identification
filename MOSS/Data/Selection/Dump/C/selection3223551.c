#include <stdio.h>

int main(void){
  int n, a[100], i, j, minj, x, sum;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sum = 0;

  for (i = 0; i < n; i++) {
    minj = i;
    for (j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      sum++;
      x = a[i];
      a[i] = a[minj];
      a[minj] = x;
    }
  }

  for (i = 0; i < n; i++) {
    if (i < n - 1) {
      printf("%d ", a[i]);
    }
    else if (i == n - 1) {
      printf("%d\n", a[i]);
      printf("%d\n", sum);
    }
  }
}
