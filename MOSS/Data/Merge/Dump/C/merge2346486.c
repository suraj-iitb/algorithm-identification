#include <stdio.h>

void merge(int [],int,int,int);
void mergeSort(int [],int,int);
#define MAX 500000
#define SENTINEL 2000000000
   
int L[MAX/2+2], R[MAX/2+2];
int count=0;

int main(){
  int n,i;
  int S[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  
  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",S[i]);
    else printf("%d ",S[i]);
  }
  printf("%d\n",count);

  return 0;
}

void merge(int *A,int left,int mid,int right){
  int i,j,k;
  int n1,n2;  
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+2],R[n2+2];
  
  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  
  i = 0;
  j = 0;
    
  for(k = left; k < right; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{ 
      A[k] = R[j++];
    }
  }
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
