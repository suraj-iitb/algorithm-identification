#include <stdio.h>

void insertionSort(int A[], int N)
{
  int i, j, k;
  int v;
    
  for (i = 1; i < N; i++) {
    v = A[i];
    j = i - 1;

    while (j >= 0 && A[j] > v) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = v;

    for (k = 0; k < N; k++) {
      if (k != N -1) {
	printf("%d ", A[k]);
      } else {
	printf("%d\n", A[k]);
      }
    }
  }
}

int main()
{
  int i;
  int N;
  int A[1000];

  scanf("%d", &N);

  for (i = 0; i < N; i++) {
    char c;
    int ret;
    ret = scanf("%d%c", &A[i], &c);
    if (ret == 1) break;
  }

  for(i = 0; i < N; i++) {
    if (i != N -1) {
      printf("%d ", A[i]);
    } else {
      printf("%d\n", A[i]);
    }
  }
  
  insertionSort(A, N);

  return 0;
}

