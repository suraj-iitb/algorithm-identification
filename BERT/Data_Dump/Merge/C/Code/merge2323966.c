#include<stdio.h>
#define INFTY 1000000000
int count=0;
void merge(int *, int, int, int);
void mergeSort(int *, int, int);
int main() {
  int i, n, left=0;
  scanf("%d", &n);
  int S[n];
  for(i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  mergeSort(S, left, n);
  for(i = 0; i < n; i++) {
    printf("%d", S[i]);
    if(i != n-1)printf(" ");
  }
  printf("\n%d\n", count);
  return 0;
}
  
void merge(int *A, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];
  for(i = 0; i < n1; i++) {
    L[i] = A[left+i];
  }
  for(i = 0; i < n2; i++) {
    R[i] = A[mid+i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++) {
    count++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
	i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int *A, int left, int right) {
  int mid;
  if(left+1 < right) {
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}