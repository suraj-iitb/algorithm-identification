#include <stdio.h>
#define MAX 1000000000
#define max 500001


int count = 0;

void merge(int *A,int left,int mid,int right){

  int i,j,k,n1,n2,L[max],R[max];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = MAX;
  R[n2] = MAX;

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

void mergeSort(int *A,int left,int right){

  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}


int main(){

  int i,n,A[max];

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]);
  mergeSort(A,0,n);
  for(i = 0; i < n-1; i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);


  return 0;
}
