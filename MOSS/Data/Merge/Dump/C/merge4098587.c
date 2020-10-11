#include<stdio.h>
#define N 1000000000
#define M 500000

int merge(int *,int,int,int,int,int);
int mergeSort(int *,int,int);
int main(){
  int n,i,S[M],cnt;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  cnt=mergeSort(S,0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n%d\n",S[n-1],cnt);
  return 0;
}

int merge(int *A,int left,int mid,int right,int n1,int n2){
  int L[n1],R[n2];
  int i,j,k;
  int static cnt=0;
  for(i=0;i<n1;i++)
    L[i]=A[left+i];
  for(i=0;i<n2;i++)
    R[i]=A[mid+i];
  L[n1]=N+1;
  R[n2]=N+1;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i+=1;
    }else{
      A[k]=R[j];
      j+=1;
    }
    cnt++;
  }
  return cnt;
}

int mergeSort(int *A,int left,int right){
  int mid,n1,n2;
  if(left+1<right){
    mid=(left+right)/2;
    n1=mid-left;
    n2=right-mid;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    return merge(A,left,mid,right,n1,n2);
  }
}

