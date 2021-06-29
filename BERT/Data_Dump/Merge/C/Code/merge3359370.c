#include<stdio.h>
#define MAX 500000
#define INFTY 2000000000
int L[MAX/2+2],R[MAX/2+2];
int count;
void merge(int *,int ,int ,int ,int);
void mergesort(int * ,int ,int,int);
int main(){
  int A[MAX],n,i;
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  mergesort(A,n,0,n);
  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%d\n",A[i]);
    else
      printf("%d ",A[i]);
  }
  printf("%d\n",count);
  return 0;
}
void merge(int *A,int n,int left,int mid,int right){
  int i,j,k,num1,num2;
  num1=mid-left;
  num2=right-mid;
  for(i=0;i<num1;i++)
    L[i]=A[left+i];
  for(j=0;j<num2;j++)
    R[j]=A[mid+j];
  L[num1]=INFTY;
  R[num2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
}
void mergesort(int *A,int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

