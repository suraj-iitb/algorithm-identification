#include<stdio.h>

void trace(int A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}


int bubbleSort(int A[], int n) {
    int tmp, flag = 1, count = 0;
    while (flag) {
        flag = 0;
        for (int j = n - 1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                tmp = A[j]; A[j] = A[j-1]; A[j-1] = tmp;
                flag = 1;
                count++;
            }
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
  int count = bubbleSort(A, n);
  trace(A, n);
  printf("%d\n", count);

  return 0;
}
