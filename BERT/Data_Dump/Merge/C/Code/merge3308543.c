#include <stdio.h>
#include <limits.h>

int cnt = 0;

void merge(int *A, int left, int mid, int right) {
  int n1, n2, L[500000], R[500000], i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = INT_MAX;
  i = j = 0;
  for (k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    cnt++;
  }
}

void mergeSort(int *A, int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n, A[500000],i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  mergeSort(A, 0, n);
  for (i = 0; i < n; i++) {
    printf("%d", A[i]);
    if (i != n - 1) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n", cnt);
  return 0;
}

