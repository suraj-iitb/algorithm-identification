#include <stdio.h>
#include <math.h>
#define N 500000
#define MAX 2147483647

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int n,num=0;

int main(){
  int i,S[N];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++) printf("%d ",S[i]);
  printf("%d\n",S[n-1]);
  printf("%d\n",num);

  return 0;
}

void merge(int *A,int left,int mid,int right){
  int i,j,k,n1,n2;

  n1=mid-left;
  n2=right-mid;

  int L[n1+1],R[n2+1];

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=MAX;
  R[n2]=MAX;

  i=j=0;

  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      num++;
    }
    else{
      A[k]=R[j];
      j++;
      num++;
    }
  }
}

void mergeSort(int *A,int left,int right){
  int i,mid;
  
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);

  }
}
