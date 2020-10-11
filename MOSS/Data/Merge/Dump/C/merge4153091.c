#include<stdio.h>

#define INFTY 1000000001
#define MAX 500000

void mergeSort(int*,int,int);
void merge(int *,int,int,int);

int count;

int main(){
  int n,S[MAX],i;

  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++)
    printf("%d ",S[i]);

  printf("%d\n",S[i]);
  
  printf("%d\n",count);

  return 0;
}

void merge(int*A, int left,int mid,int right){
  int n1,n2,k,i,j;
  
  n1 = mid - left;
  n2 = right - mid;
  
  int L[n1],R[n2];
  
  for (i=0;i<n1;i++)
    L[i] = A[left + i];
  
  for (i=0;i<n2;i++)
    R[i] = A[mid + i];
  
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k=left;k<right;k++)
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      count++;
    }
}

void mergeSort(int *A, int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

