#include<stdio.h>

#define SENTINEL 1000000000

int count = 0;

void Merge(int A[],int left,int mid,int right){
  int n1 = mid - left, n2 = right - mid;
  int i,j,k;
  int L[n1+1],R[n2+1];

  for(i = 0; i < n1; i++){
    L[i] = A[left+i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid+i];
  }

  L[n1] = SENTINEL;
  R[n2] = SENTINEL;

  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }else{
      A[k] = R[j];
      j = j + 1;
    }
  }
}

MergeSort(int A[], int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

int main(){
  int n,i;
  int A[500000];

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  MergeSort(A,0,n);

  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0;
}
