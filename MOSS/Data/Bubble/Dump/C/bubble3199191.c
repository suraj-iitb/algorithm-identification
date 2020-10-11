#include <stdio.h>

int main(void) {
  int i, j;
  int n;
  int count = 0;
  int temp;

  scanf("%d", &n);

  int a[n + 1];

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        count++;
      }
    }
  }

  for (i = 0; i < n; i++)
    if (i < n - 1) {
      printf("%d ", a[i]);
    } else {
      printf("%d\n%d\n", a[i], count);
    }

  return 0;
}

