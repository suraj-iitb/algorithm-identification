#include <stdio.h>

int main() {
  int n, min;
  scanf("%d", &n);
  int a[n];
  int i, j;
  int count = 0;

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (i = 0; i < n; i++) {
    int temp;
    min = i;
    for (j = i; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
    if (i != min)
      ++count;
  }

  for (i = 0; i < n; i++) {
    if (i == n - 1) {
      printf("%d\n", a[i]);
    } else {
      printf("%d ", a[i]);
    }
  }
  printf("%d\n",count);

  return 0;
}

