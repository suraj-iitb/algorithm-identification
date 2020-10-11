#include <stdio.h>

int main(void) {
  int i, j, k, a[100], n, l, minj, temp, count = 0;
  char buf[2];
  scanf("%d", &l);
  for (n = 0; n < l && (j = scanf("%d%1[\n]", a+n, buf)) == 1; n++) ;
  if (j == 2)
  n++;

  for (i = 0; i < l; i++) {
    minj = i;
    for (j = i; j < l; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (a[i] != a[minj]) {
      count++;
    }
    temp = a[i];
    a[i] = a[minj];
    a[minj] = temp;
  }

    for (k = 0; k < l; k++) {
      printf("%d", a[k]);
      if (k < n - 1) {
        printf(" ");
      }
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
  }

