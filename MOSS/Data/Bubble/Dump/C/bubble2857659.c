#include <stdio.h>

int bubbleSort(int A[], int N) {
  int flag = 1;
  int n = 0, j, tmp;

  while(flag) {
    flag = 0;
    for(j = N - 1;j > 0;j--) {
      if(A[j] < A[j - 1]) {
        tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;

        flag = 1;
        n++;
      }
    }
  }

  return n;
}

int main() {
  int n, m, i, a[100];

  scanf("%d", &n);
  for(i = 0;i < n;i++)
    scanf("%d", &a[i]);

  m = bubbleSort(a, n);

  for(i = 0;i < n - 1;i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", m);

  return 0;
}

