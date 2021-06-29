#include <stdio.h>
#include <stdlib.h>
#define N 500000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count;

int main()
{
  int n,i,S[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %d",&S[i]);
  }

  mergeSort(&S[0],0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n");

  printf("%d\n",count);

  return 0;
}

void merge(int *A,int left,int mid,int right)
{
  int n1,n2,i,j=0,k=0;

  n1 = mid - left;
  n2 = right - mid;

  int L[n1],R[n2];

  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid+i];
  }
  L[n1] = 1000000000;
  R[n2] = 1000000000;

  for(i=left;i<right;i++){
    count++;
    if(L[j]<=R[k]){
      A[i] = L[j];
      j += 1;
    }
    else{
      A[i] = R[k];
      k += 1;
    }
  }
}
void mergeSort(int *A,int left,int right)
{
  int mid;

  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
