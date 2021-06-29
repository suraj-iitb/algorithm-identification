#include <stdio.h>
#include <stdlib.h>
/*#include <math.h> INFINITY*/

#define MAX 500000
#define INFINITY 1000000001

void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int count = 0;

int main(){
  int *A, n, i;
  scanf("%d",&n);
  A = malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A, 0, n);
  for(i = 0; i < n - 1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n - 1]);
  printf("%d\n",count);
  
  return 0;
}

void mergeSort(int *A, int left, int right){
  int mid;
  if(left + 1 != right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
void merge(int *A, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

