#include <stdio.h>

#define N 500000
#define INFTY 1000000000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count = 0;
int main(){
  int n, A[N], i, j;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);

  mergeSort(A, 0, n);

  for(i = 0; i <= n-2; i++)
    printf("%d ", A[i]);
  printf("%d\n%d\n", A[i], count);

  return 0;
}

void merge(int A[], int left, int mid, int right){
  int n1 = mid - left, n2 = right - mid;
  int L[n1], R[n2], i, j, k;

  for(i = 0; i <= n1-1; i++)
    L[i] = A[left + i];

  for(i = 0; i <= n2-1; i++)
    R[i] = A[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;
  for(k = left; k <= right-1; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i += 1;
      count++;
    }

    else{
      A[k] = R[j];
      j += 1;
      count++;
    }
  }
}

void mergeSort(int A[], int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

