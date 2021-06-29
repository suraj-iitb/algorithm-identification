#include <stdio.h>
#include <stdlib.h>
#define INFTY 2147483647

int cnt = 0;
void merge(int *A, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int *L = (int *)malloc(sizeof(int) * (n1+1));
  int *R = (int *)malloc(sizeof(int) * (n2+1));
  for (int i = 0; i < n1; i++)  {
    L[i] = A[left + i];
    //printf("%d ", L[i]);
  }
  //printf("\n");
  for (int i = 0; i < n2; i++)  {
    R[i] = A[mid + i];
    //printf("%d ", R[i]);
  }
  //printf("\n");
  L[n1] = INFTY;
  R[n2] = INFTY;
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++){
    if (L[i] <= R[j]){
      cnt++;
      A[k] = L[i];
      i = i + 1;
    } else {
      cnt++;
      A[k] = R[j];
      j = j + 1;
    }
  }
}
void mergeSort(int *A, int left, int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main (){
  int n;
  scanf("%d", &n);
  int *A = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  mergeSort(A, 0, n);

  for (int i = 0; i < n-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n-1]);
  printf("%d\n", cnt);
  return 0;
}

