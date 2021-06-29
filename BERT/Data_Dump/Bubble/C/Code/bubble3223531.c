#include <stdio.h>

int main(void){
  int n, a[100], i, j, flag, x, sum;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sum = 0;
  flag = 1;
  i = 0;
  while (flag) {
    flag = 0;
    for (j = n - 1; j >= i + 1; j--) {
      if (a[j] < a[j-1]) {
        x = a[j];
        a[j] = a[j-1];
        a[j-1] = x;
        flag = 1;
        sum++;
      }
    }
    i++;
  }

  for ( i = 0; i < n; i++) {
    if ( i < n - 1) {
      printf("%d ", a[i]);
    }
    else if (i == n - 1) {
      printf("%d\n", a[i]);
      printf("%d\n", sum);
    }
  }
}
