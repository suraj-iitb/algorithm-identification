#include <stdio.h>

int A[500000],count=0;

void merge(int *A, int left, int mid, int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  
  int L[n1], R[n2];
  
  for (i=0; i<n1; i++)
    L[i] = A[left + i];
  for (i=0; i<n2; i++)
    R[i] = A[mid + i];
  L[n1] = 1000000001;
  R[n2] = 1000000001;
  i = 0;
  j = 0;
  for (k=left; k<right; k++){
    if (L[i] <= R[j]){
      count++;
      A[k] = L[i];
      i = i + 1;
    }
    else {
      count++;
      A[k] = R[j];
      j = j + 1;
    }
  }
}


void mergeSort(int *A, int left, int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int i, n;

  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);
  mergeSort(A,0,n);

  for(i=0; i<n-1; i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[i],count);

  return 0;
}
  

  
  

