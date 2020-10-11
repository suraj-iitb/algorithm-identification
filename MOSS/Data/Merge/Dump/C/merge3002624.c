#include<stdio.h>

#define MAX 500000
#define INFTY 1000000000

int count = 0;

void merge(int *A,int left,int mid,int right){
  int i,j,k,n1,n2,L[MAX],R[MAX];

  n1 = mid - left;
  n2 = right - mid;

  for (i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (i = 0 ; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for( k = left; k < right; k++){
    count++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
  
}

void mergeSort(int *A,int left,int right){
  int mid;

  if ((left + 1) < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}


int main(){
  int i,l,A[MAX];

  scanf("%d",&l);
  for(i = 0; i < l; i++)
    scanf("%d",&A[i]);
  mergeSort(A,0,l);
  
  for(i = 0; i < l-1; i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[l-1],count);
  
  return 0;
}

