#include<stdio.h>
#define N 500000
#define NN 250000
#define INFTY 1000000001

int cnt=0;

void merge(int A[],int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  n1=mid-left;
  n2=right-mid;
  int L[n1],R[n2];
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      cnt++;
      A[k]=L[i];
      i=i+1;
    }
    else {
      cnt++;
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
      

int main(){
  int n,i;
  int A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
    if(i!=n-1)printf("%d ",A[i]);
    else printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}
  

