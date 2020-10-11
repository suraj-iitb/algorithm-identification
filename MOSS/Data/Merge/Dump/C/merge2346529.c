#include<stdio.h>
#define INFINITY 10000000000
#define N 500000

int count = 0;

void marge(int *A, int left, int mid, int right) {
  int n1, n2, i, j, k, L[N], R[N];

  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++) {
    count++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int *A, int left, int right) {
  int mid;
  
  if(left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    marge(A, left, mid, right);
  }
}

int main() {
  int i, n, A[N];

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  mergeSort(A, 0, n);

  for(i = 0; i < n; i++) {
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
    
}
