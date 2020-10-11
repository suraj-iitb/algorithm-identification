#include<stdio.h>

void trace(int A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int selectionSort(int A[], int n) {
    int min, tmp, count = 0;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[min]) min = j;
        }
        if (i != min) {
            tmp = A[i]; A[i] = A[min]; A[min] = tmp;
            count++;
        }
    }

    return count;
}

int main(void) {
  int A[100], i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
      scanf("%d", &A[i]);
  }
  int count = selectionSort(A, n);
  trace(A, n);
  printf("%d\n", count);

  return 0;
}
