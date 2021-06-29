#include <stdio.h>

int main(void) {
  int i, j, k, v, a[100], n, l;
  char buf[2];
  scanf("%d", &l);
  for (n = 0; n < l && (j = scanf("%d%1[\n]", a+n, buf)) == 1; n++) ;
  if (j == 2)
  n++;

  for (k = 0; k < n; k++) {
    printf("%d", a[k]);
    if (k < n - 1) {
      printf(" ");
    }
  }
  printf("\n");

  for (i = 1; i < n; i++) {
    v = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for (k = 0; k < n; k++) {
      printf("%d", a[k]);
      if (k < n - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
  }

