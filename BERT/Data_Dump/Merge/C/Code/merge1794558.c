#include <stdio.h>

void Merge(int*, int, int, int);
void MergeSort(int*, int, int);

int count=0;

int main(){
  int i, n, A[500000];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  MergeSort(A,0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  
  return 0;
}

void Merge(int *A, int left, int mid, int right){
  int i, j, k, n1, n2;
  int L[250002], R[250002];
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++)
    L[i] = A[left+i];
  for(i=0;i<n2;i++)
    R[i] = A[mid+i];
  L[n1]=2000000000;
  R[n2]=2000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }
}

void MergeSort(int *A, int left, int right){
  int mid;
  if (left+1<right){
    mid = (left + right)/2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}
