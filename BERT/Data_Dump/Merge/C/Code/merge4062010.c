#include<stdio.h>
#define INFTY 1000000001
#define N 500000

int cnt;

void merge(int A[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  int L[n1],R[n2];
  for(i=0;i<n1;i++) L[i]=A[left + i];
  for(i=0;i<n2;i++) R[i]=A[mid + i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      cnt++;
    }
    else{
      A[k]=R[j];
      j=j+1;
      cnt++;
    }
  }
}

void  mergeSort(int A[],int left,int right){
  int mid;
  if (left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){

  int i,n,S[N];

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",cnt);

  return 0;
}

