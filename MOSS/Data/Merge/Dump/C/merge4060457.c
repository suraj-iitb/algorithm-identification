#include <stdio.h>
#include <stdlib.h>

#define N 500000
#define INFTY (10000000001)

int countMerge = 0;

void merge(long *, int, int, int);
void mergeSort(long *, int, int);
long *makeArray(int);
void copyArray(long *, long *, int, int);

int main() {
  int i, n;
  long A[N];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &A[i]);
  }

  mergeSort(A, 0, n);

  for (i = 0; i < n; i++) {
    if (i == 0) printf("%d", A[i]);
    else printf(" %ld", A[i]);
  }
  printf("\n");
  printf("%d\n", countMerge);
  
  return 0;
}

void mergeSort(long *A, int left, int right) {
  int mid;
  
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
  
}

void merge(long *A, int left, int mid, int right) {
  int i, j, k;
  
  int nl = mid - left;
  int nr = right - mid;
  
  long *L = makeArray(nl + 1);
  long *R = makeArray(nr + 1);
  
  copyArray(L, A, nl, left);
  copyArray(R, A, nr, mid);
  L[nl] = R[nr] = INFTY;

  j = i = 0;
  for (k = left; k < right; k++) {
    countMerge++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
  
  free(L);
  free(R);
}

long *makeArray(int size) {
  return (long *)malloc(size * sizeof(long));
}

void copyArray(long *A, long *B, int n, int m) {
  int i;
  for (i = 0; i < n; i++) {
    A[i] = B[m + i];
  }
}

