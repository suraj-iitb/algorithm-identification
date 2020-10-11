#include <stdio.h>
#define MAX 500000
#define INFTY 1000000001

int L[MAX/2+1], R[MAX/2+1], count = 0;

void merge(int *A, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  for (i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    count++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int *A, int left, int right) {
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

void print_array(int *A, int N) {
  int i;
  for(i = 0; i < N - 1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[i]);
}


int main() {
  int A[MAX], n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  mergeSort(A, 0, n);
  print_array(A, n);
  printf("%d\n", count);
  return 0;
}

