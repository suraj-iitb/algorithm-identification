#include<stdio.h>
#include<stdlib.h>
#define INFTY 1000000001

void merge(int[], int, int, int);
void mergeSort(int[], int, int);

int count=0;

int main()
{
  int n,i;
  int left,right,mid;
  int A[500000];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  left = 0;
  mid = i/2;
  right = i;

  mergeSort(A,left,right);
  
  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],count);
  

  return 0;
}

void merge(int A[], int left, int mid, int right)
{
  int n1, n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;

  int L[n1];
  int R[n2];

  for(i=0; i<n1; i++)
    L[i] = A[left+i];

  for(i=0; i<n2; i++)
    R[i] = A[mid+i];

  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      count++;
      A[k] = L[i];
      i += 1;
    }
    else {
      count++;
      A[k] = R[j];
      j += 1;
    }
  }
}

void mergeSort(int A[], int left, int right)
{
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
