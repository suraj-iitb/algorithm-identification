#include <stdio.h>

#define INFTY 2000000000

int L[250002],R[250002];

int cnt;

void merge(int *A, int n, int left, int mid, int right){

  int n1=mid-left;
  int n2=right-mid;
  int i,j=0,k;

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=R[n2]=INFTY;

  i=0;

  for(k=left;k<right;k++){

    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }
    else{
      A[k]=R[j++];
    }
  }
}

void mergesort(int *A, int n, int left, int right){

  int mid;

  if(left+1<right){
    mid=(left+right)/2;

    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int main(){

  int i,n;

  cnt=0;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mergesort(A,n,0,n);

  for(i=0;i<n-1;i++) printf("%d ",A[i]);

  printf("%d\n", A[i]);

  printf("%d\n",cnt);

  return 0;

}

