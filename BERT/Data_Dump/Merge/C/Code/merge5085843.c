#include <stdio.h>
#define SENTINEL 2000000000

int cnt;

void merge(int A[], int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];
  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int a[], int left, int right){
  int i;
  if(left+1 < right){
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(){
  int i, n, A[500000];
  cnt = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  mergeSort(A, 0, n);
  printf("%d", A[0]);
  for(i = 1; i < n; i++) printf("% d", A[i]);
  printf("\n");
  printf("%d\n", cnt);

  return 0;
}

