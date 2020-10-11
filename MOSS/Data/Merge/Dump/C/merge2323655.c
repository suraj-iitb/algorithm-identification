#include <stdio.h>

#define MAX 500000
#define SMAX 2000000000

int n,A[MAX],count=0;

void mergeSort(int*,int,int);
void merge(int*,int,int,int);

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  mergeSort(A,0,n);
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k,L[MAX/2+2],R[MAX/2+2];
  n1 = mid-left;
  n2 = right - mid;
  for(i=0;i<n1;i++) L[i] = A[left+i];
  for(i=0;i<n2;i++) R[i] = A[mid+i];
  L[n1] = SMAX;
  R[n2] = SMAX;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i+1;
    }
    else {
      A[k] = R[j];
      j = j+1;
    }
  }
}
