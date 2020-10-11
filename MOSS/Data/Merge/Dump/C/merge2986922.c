#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INFTY 10000000000
void merge(int*,int,int,int);
void mergesort(int*,int,int);
int count=0;
int main(){

  int i,n,left,right;

  scanf("%d",&n);
  int A[n];
  left = 0;
  right = n;
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergesort(A,left,right);

  for(i=0;i<n;i++){
    if(i==n-1){
      printf("%d\n",A[i]);
    }
    else{
      printf("%d ",A[i]);
    }
  }

  printf("%d\n",count);
  
  return 0;
  
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1];
  int R[n2];
  for(i=0;i<=n1-1;i++){
    L[i] = A[left+i];
  }
  for(i=0;i<=n2-1;i++){
    R[i] = A[mid+i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
    if(L[i]<= R[j]){
      A[k] = L[i];
      i=i+1;
      count++;
    }
    else{
      A[k]=R[j];
      j=j+1;
      count++;
    }
  }
}
void mergesort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

  

