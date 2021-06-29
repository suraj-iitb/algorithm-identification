#include<stdio.h>

int count = 0;

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int main(){
  int i, n;
  scanf("%d", &n);
  int A[n];
  for(i = 0 ; i < n ; i++) scanf("%d", &A[i]);
  mergeSort(A, 0, n);
  for(i = 0 ; i < n ; i++){
    if(i != n - 1)printf("%d ", A[i]);
    else printf("%d\n", A[i]);
  }
  printf("%d\n", count);
}

void merge(int *A, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i, L[n1 + 1], R[n2 + 1];
  for(i = 0 ; i < n1 ; i++) L[i] = A[left + i];
  for(i = 0 ; i < n2 ; i++) R[i] = A[mid + i];
  L[n1] = 1000000000;
  R[n2] = 1000000000;
  i = 0;
  int j = 0, k;
  for(k = left ; k < right ; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
    count++;
  }
}

void mergeSort(int *A, int left, int right){
  if(left + 1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

