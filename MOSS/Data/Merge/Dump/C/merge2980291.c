#include <stdio.h>
#include <limits.h>

#define N 500000

void merge(int*, int, int, int);
void mergesort(int*, int, int);

int count = 0;

int main(){
  int A[N];
  int right, mid, i;

  scanf("%d", &right);
  for(i = 0; i < right; i++){
    scanf("%d", &A[i]);
  }
  
  mergesort(A,0, right);
  
  for(i = 0; i < right-1; i++){
    printf("%d ", A[i]);
  }

  printf("%d\n", A[i]);
  printf("%d\n", count);
  
  return 0;
}

void merge(int*A, int left, int right, int mid){
  int L[N/2+5], R[N/2+5];
  int n1 = mid - left;
  int n2 = right - mid;
  int i, j , k;

  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  i = 0;
  j = 0;
  
  for(k = left; k < right; k++){
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

void mergesort(int *A, int left, int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, right, mid);
  }
}

