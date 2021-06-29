#include <stdio.h>
#include <stdlib.h>
#define  MAX 500000
#define INFTY 10000000000000000
int S[MAX],count=0;

void merge(int A[], int left,int mid, int right)
{
  int n1,n2,i,j,k;
  int *L,*R;
  n1 = mid - left;
  n2 = right - mid;
  L = (int *)malloc(sizeof(int)*(n1+1));
  R = (int *)malloc(sizeof(int)*(n2+1));
  for(i = 0;i < n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }
    else{
      A[k] = R[j];
      j++;
      count++;
    }
  }
  free(L);
  free(R);
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

int main()
{
  int n,i;
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i = 0;i < n;i++){
    printf("%d",S[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
