#include <stdio.h>
#include <limits.h>
int count = 0;
void Merge(int A[],int left,int mid,int right) {
  int n1, n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1];
  int R[n2+1];
  
  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(i =0;i<n2;i++){
    R[i] = A[mid+i];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if (L[i]<=R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
    count = count+1;
  }
}
void mergeSort(int A[],int left,int right){
  int mid;  
  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}
int main(void){
  int n,i;
  scanf("%d",&n);
  int A[n];
  for (i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A, 0, n);
  for (i=0;i<n;i++){
    if(i == n - 1){
        printf("%d\n",A[i]);
    }else{
      printf("%d ", A[i]);
    }
  }
  printf("%d\n",count);
}
