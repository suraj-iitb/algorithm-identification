#include<stdio.h>
#include<stdlib.h>

#define N 500000
#define INFTY 10000000000

int count,A[N];

void merge(int *A,int left,int mid,int right){
  
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;

  long L[n1],R[n2];
  
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i=i+1;
    }
    else {
      A[k] = R[j];
      j = j+1;
    }
  }
}

void mergesort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergesort(A,left, mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}



int main(){

  int i,j,n,x,y,mid;
  int A[N];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mergesort(A,0,n);

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",count);
  
  return 0;
}

