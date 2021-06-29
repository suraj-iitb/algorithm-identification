#include <stdio.h>

int selectionSort(int A[], int N) {
  int n = 0, i, j, tmp, min;

  for(i = 0;i < N;i++) {
    min = i;
    for(j = i;j < N;j++)
      min = A[j] < A[min] ? j : min;

    if(min != i) {
      tmp = A[min];
      A[min] = A[i];
      A[i] = tmp;

      n++;
    }
  }

  return n;
}

int main() {
  int n, m, i, a[100];

  scanf("%d", &n);
  for(i = 0;i < n;i++)
    scanf("%d", &a[i]);

  m = selectionSort(a, n);

  for(i = 0;i < n - 1;i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", m);

  return 0;
}

