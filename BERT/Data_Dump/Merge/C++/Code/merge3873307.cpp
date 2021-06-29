#include<stdio.h>
#define LIM 500000
#define SENTINEL 1000000000
int cnt = 0;

void merge(int A[], int left, int middle, int right) {
  int l = middle - left;
  int r = right - middle;
  int L[l], R[r];
  for ( int i = 0; i < l; i++ ) L[i] = A[left + i];
  for ( int i = 0; i < r; i++ ) R[i] = A[middle + i];
  L[l] = R[r] = SENTINEL;
  l = r = 0;

  for ( int i = left; i < right; i++ ) {
    if ( L[l] <= R[r] ) A[i] = L[l++];
    else A[i] = R[r++];
    cnt++;
  }
}

void mergeSort(int A[], int left, int right) {
  if ( left + 1 < right ) {
    int middle = (left + right) / 2;
    mergeSort(A, left, middle);
    mergeSort(A, middle, right);
    merge(A, left, middle, right);
  }
}

int main() {
  int n, A[LIM];

  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) scanf("%d", &A[i]);

  mergeSort(A, 0, n);

  for ( int i = 0; i < n; i++ ) {
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", cnt);

  return 0;
}
