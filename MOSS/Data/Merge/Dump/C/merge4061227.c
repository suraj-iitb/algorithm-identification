#include <stdio.h>
#define N 500000
#define INFTY 1000000000

int c;
void merge(int *A, int left, int mid, int right){
    int n1, n2, R[N], L[N];
    int i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  for(i = 0; i<n1; i++) L[i] = A[left + i];
  for(i = 0; i<n2; i++) R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left; k<right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
    c++;
    }
}

void mergeSort(int *A, int left, int right){
    int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void){
    int A[N], n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &A[i]);
    c=0;
    mergeSort(A, 0, n);
    for(i=0; i<n-1; i++) printf("%d ", A[i]);
    printf("%d\n", A[n-1]);
    printf("%d\n", c);
    return 0;
}
