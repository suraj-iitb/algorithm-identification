#include <stdio.h>

#define  MID  500000
#define   N   1000000
#define INFTY 2000000000

void mergeSort(int*,int,int);
void merge(int*,int,int,int);

int count=0;

int main(){
  int i;
  int n;
  int A[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);  
  }

  mergeSort(A,0,n);

  for(i=0;i<n-1;i++){
  printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
  
  return 0;
}

void mergeSort(int *A,int left,int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

void merge(int *A,int left,int mid,int right){

  int i;
  int j;
  int k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[MID];
  int R[MID];
  
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
    if(L[i] <= R[j]){
      A[k]=L[i];
      i = i + 1;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
    }
    count++;
  }
}
