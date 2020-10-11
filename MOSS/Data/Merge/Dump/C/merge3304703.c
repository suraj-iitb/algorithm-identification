#include<stdio.h>

#define N 500000
#define INFTY 1000000000

void merge(int *,int ,int,int);

void mergeSort(int * , int, int);

int A[N];
int count;

int main(){
  int i,j,n,left,right;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }

  left = 0;
  right = n;
  mergeSort(A,left,right);
  
  for(j = 0;j < n;j++){
    if(j == n - 1){
      printf("%d",A[j]);
    }
    else printf("%d ",A[j]);
  }
  printf("\n%d\n",count);
  
  return 0;
}


void mergeSort(int A[],int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1],R[n2];
  for(i = 0;i <= n1 -1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i <= n2 - 1;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k <= right - 1;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }
    else{
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  }
}

