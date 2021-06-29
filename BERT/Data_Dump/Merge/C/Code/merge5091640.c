#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000000
#define SIZE 500000

int count = 0;

void merge(int A[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;

  int *L = malloc(sizeof(int)*(n1+1));
  int *R = malloc(sizeof(int)*(n2+1));
  for (i = 0; i <= n1-1; i++) {
    L[i] = A[left+i];
  }
  for (i = 0; i <= n2-1; i++) {
    R[i] = A[mid+i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for (k = left; k < right; k++) {
    count++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
  }


  free(L);
  free(R);
}

void mergeSort(int A[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int i, x;
  int a[SIZE];
  scanf("%d", &x);
  for (i = 0; i < x; i++) {
    scanf("%d", &a[i]);
  }

  mergeSort(a, 0, x);
  for (i = 0; i < x-1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n", a[x-1]);
  printf("%d\n", count);

  return 0;

}
