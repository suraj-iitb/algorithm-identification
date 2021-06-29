#include <stdio.h>
#include <stdlib.h>

#define N 500000
#define INFTY 1000000000

int n, count = 0;
int A[N];

void merge(int *,int, int, int);
void mergeSort(int *, int, int);

int main()
{

  int i, j;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  mergeSort(A, 0, n);

  for(j=0; j<n; j++){
    if(j == n-1) printf("%d\n",A[j]);
    else printf("%d ",A[j]);
  }

  printf("%d\n",count);

  return 0;
}

void merge(int *A, int left, int mid, int right)
{

  int n1, n2, i, j, k;
  int *L, *R;

  n1 = mid - left;
  n2 = right - mid;

  L = (int *)malloc(sizeof(int)*(n1+1));
  R = (int *)malloc(sizeof(int)*(n2+1));

  for(i=0; i<=(n1-1); i++){
    L[i] = A[left+i];
  }

  for(i=0; i<=(n2-1); i++){
    R[i] = A[mid+i];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k=left; k<=(right-1); k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
    count++;
  }

  free(L);
  free(R);

}

void mergeSort(int *A, int left, int right)
{

  int mid; 

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
