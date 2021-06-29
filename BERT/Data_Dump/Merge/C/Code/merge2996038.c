#include<stdio.h>
#define INFTY 1000000000
#define N 500000

void merge(int *, int ,int ,int);
void mergeSort(int *, int, int);

int n,count=0;

int main(){
  int A[N],i;
  scanf("%d",&n);
  for(i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  
  for(i=0 ; i<n ; i++){
    if(i<n-1)
      printf("%d ",A[i]);
    else
      printf("%d\n",A[i]);
  }
  printf("%d\n",count);
  return 0;
}

void merge(int *A,int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1];
  int R[n2];
  int i,j,k;
  for (i = 0 ; i< n1 ; i++){
    L[i] = A[left + i];
  }
  for (i = 0 ; i<n2 ; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k=left; k < right ; k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i=i+1;
    }
    else{
      A[k] = R[j];
      j=j+1;
    }
    count++;
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

