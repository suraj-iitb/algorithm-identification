#include<stdio.h>
void merge(int *,int,int,int);
void mergeSort(int*,int,int);
#define N 500000
#define INFTY 10000000000
/*外部変数*/
int count;
int main(){
  int A[N],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  mergeSort(A,0,n);
  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}
void merge(int *A,int left,int mid,int right){
  int Left[N],Right[N],nL,nR,i,j,k;
  nL=mid-left;
  nR=right-mid;
  for(i=0;i<nL;i++)Left[i]=A[left+i];
  for(i=0;i<nR;i++)Right[i]=A[mid+i];
  Left[nL]=INFTY;
  Right[nR]=INFTY;
  i=0;
  j=0;
  /*統治*/
  for(k=left;k<right;k++){
    /*昇順*/
    if(Left[i]<=Right[j]){
      A[k]=Left[i];
      i=i+1;
    }
    else{
      A[k]=Right[j];
      j=j+1;
    }
    count++;
  }
}
/*分割*/
void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    /*左半分*/
    mergeSort(A,left,mid);
    /*右半分*/
    mergeSort(A,mid,right);
    /*統合*/
    merge(A,left,mid,right);
  }
}


