#include <stdio.h>
#include <stdlib.h>

#define INFTY 1000000001

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int compcount = 0;

int main()
{
  int i, n, S[500000];

  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d",&S[i]);
  }
  
  mergeSort(S, 0, n);
    
  for(i = 0; i < n; i++) {
    if(i) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",compcount);

  return 0;
}

void merge(int *A, int left, int mid, int right)
{
  int i, j, k, n1, n2, *L, *R;
  n1 = mid - left;
  n2 = right - mid;

  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));

  for(i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;

  i = j = 0;
  for(k = left; k < right; k++) {
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    compcount++;
  }
  
  free(L);
  free(R);
}

void mergeSort(int *A, int left, int right)
{
  int mid;
  
  if(left + 1 < right) {
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A,left, mid, right);
  }
}

