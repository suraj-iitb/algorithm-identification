#include <stdio.h>
#define MAX 500000
#define INFTY 2000000000

int L[MAX/2+2],R[MAX/2+2];
int count=0;

void merge(int A[],int n,int left, int mid, int right){
  int i,j,k;
  int n1,n2;
  n1=mid-left;
  n2=right-mid;
  for (i = 0; i < n1; i++) L[i]=A[left+i];
  for (i = 0; i < n2; i++) R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]) A[k]=L[i++];
    else A[k]=R[j++];
  }
}

void mergesort(int A[],int n,int left,int right){
  int mid;
  if(left+1<right){
  mid=(left+right)/2;
  mergesort(A,n,left,mid);
  mergesort(A,n,mid,right);
  merge(A,n,left,mid,right);
  }
}

int main(){
  int A[MAX],n,i;
  scanf("%d\n",&n);
  for(i=0;i<n;i++){
      scanf("%d",&A[i]);
  }
  mergesort(A,n,0,n);
  for(i=0;i<n;i++){
    if(i==n-1)  printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",count);
  return 0;
}
