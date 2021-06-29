#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500000
#define INF 1000000000

int L[N], R[N];
int count = 0;

void merge(int A[], int left, int mid, int right)
{
  int n1, n2, i, j, k;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid + i];

  L[n1] = INF;
  R[n2] = INF;

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

void mergeSort(int A[], int left, int right)
{
  int mid;

  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void)
{
  int i, n, A[N];

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  mergeSort(A, 0, n);

  for(i = 0; i < n; i++){
    if(i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
}

