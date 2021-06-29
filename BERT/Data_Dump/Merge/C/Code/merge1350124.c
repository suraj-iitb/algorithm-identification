#include <stdio.h>
#include <stdlib.h>

#define N 500000
#define INFTY 1000000001

void mergeSort(int, int);
void merge(int, int, int);

int A[N], c = 0;

int main(){
  
  int i, n, left, mid, right;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  
  left = 0;
  right = n;

  mergeSort(left, right);

  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  
  printf("\n%d\n", c);

  return 0;
  
}

void merge(int left, int mid, int right){
  
  int n1, n2, i, j, k;
  int L[N], R[N];
  
  n1 = mid - left;
  n2 = right - mid;
  
  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid + i];
  
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      c++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      c++;
    }
  }
}

void mergeSort(int left, int right){
  
  int mid;
  
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}
