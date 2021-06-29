#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int count = 0;
int main() {
  int i,n;
  int *S;
  scanf("%d",&n);
  if(n>500000) exit(8);
  S = (int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&S[i]);
      if(S[i]<0 || S[i]>1000000000) exit(8);
    }
  mergeSort(S,0,n);
  for(i=0;i<n-1;i++)
    {
      printf("%d ",S[i]);
    }
  printf("%d\n%d\n",S[i],count);
  return 0;
}
void merge(int *A,int left,int mid,int right){
  int n1=mid - left;
  int n2=right - mid;
  int i,j,k;
  int L[n1+1];
  int R[n2+1];

  for(i=0;i<n1;i++)
    {
      L[i] = A[left+i];
    }
  for(i=0;i<n2;i++)
    {
      R[i] = A[mid+i];
    }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i=0;
  j=0;
  for(k = left;k<right;k++)
    {
      count++;
      if(L[i]<=R[j])
	{
	  A[k] = L[i];
	  i++;
	}
      else
	{
	  A[k] = R[j];
	  j++;
	}
    }
}

void mergeSort(int *A,int left,int right){
  int mid,i;
 
  if(left+1<right)
    {
      mid = (left + right)/2;
      mergeSort(A,left,mid);      
      mergeSort(A,mid,right);
      merge(A,left,mid,right);
    }
}
      

