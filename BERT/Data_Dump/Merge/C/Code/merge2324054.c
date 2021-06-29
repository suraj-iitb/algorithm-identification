#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef INFINITY
#define INFINITY 2147483647
#endif

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count=0;

int main(){
  int A[500000];
  int n, i, left, right;

  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d", &A[i]);
  left=0;
  right=n;
  mergeSort(A, left, right);

  for(i=0;i<n-1;i++) printf("%d ", A[i]);
  printf("%d\n%d\n", A[i], count);

  return 0;
}

void merge(int *A, int l, int mid, int r){
  int i, j, k, n1, n2 ,*L, *R;
  n1 = mid - l;
  n2 = r - mid;
  L = (int *)malloc((n1+1)*sizeof(int));
  R = (int *)malloc((n2+1)*sizeof(int));
  
  for(i=0;i<n1;i++) L[i] = A[l+i];
  for(i=0;i<n2;i++) R[i] = A[mid+i];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i=j=0;
  for(k=l;k<r;k++){
    if(L[i]<=R[j]){
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    count++;
  }
  free(L);
  free(R);
}

void mergeSort(int *A, int l, int r){
  int mid;
  if(l+1<r){
    mid = (l+r)/2;
    mergeSort(A, l, mid);
    mergeSort(A, mid, r);
    merge(A, l, mid, r);
  }
}
