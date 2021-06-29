#include <stdio.h>

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

#define MAX 500000
#define SEN 2000000000

int count;
int L[MAX/2+2],R[MAX/2+2];

int main(){
  int i,n;
  int S[MAX];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);

  for(i=0; i<n; i++){
    printf("%d",S[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0;
}


void merge(int *A,int left,int mid,int right){
  int i,j,n1,n2;
  n1 = mid - left;
  n2 = right - mid;
  
  for(i = 0; i<n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i<n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = SEN;
  R[n2] = SEN;
  i = 0;
  j = 0;
  for(int k=left; k<right; k++){
    count=count+1;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int *A,int left,int right){
  int mid=0;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
