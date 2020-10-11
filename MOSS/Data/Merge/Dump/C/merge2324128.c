#include<stdio.h>
#define INFTY 1000000000

int cnt = 0;

void merge(int A[], int left, int mid, int right){

  int n1,n2,i,j,k;
  int L[500000],R[500000];
  
  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(j=0;j<n2;j++){
    R[j] = A[mid+j];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k] = L[i];
      i++;
      cnt++;
    }
    else{
      A[k] = R[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int A[500000];
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",cnt);
  return 0;
}
