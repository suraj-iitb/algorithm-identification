#include <stdio.h>

void countingSort(int *a, int *b, int n, int max) {
  int i, c[max + 1];

  for(i = 0;i <= max;i++)
    c[i] = 0;

  for(i = 0;i < n;i++)
    c[a[i]]++;

  for(i = 1;i <= max;i++)
    c[i] += c[i - 1];

  for(i = 0;i < n;i++) {
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }
}

int main() {
  int i, n, a[2000000], b[2000001], max = 0;

  scanf("%d", &n);
  for(i = 0;i < n;i++) {
    scanf("%d", &a[i]);
    if(a[i] > max)
      max = a[i];
  }

  countingSort(a, b, n, max);
  for(i = 1;i < n;i++)
    printf("%d ", b[i]);
  printf("%d\n", b[i]);

  return 0;
}

