#include <stdio.h>
#include <math.h>
int count;
int mergeSort(int A[],int left,int right);
int merge(int A[],int left,int mid,int right);
int main(){
  int i,j,m,n,count,A[500000];
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  count=mergeSort(A,0,n);
  for(i = 0; i < n-1; i++)
    printf("%d ", A[i]);
  printf("%d",A[n-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}


int mergeSort(int A[],int left,int right){
  int mid,i,j,k,con=0;

  if(left+1<right){
  mid=(left+right)/2;
  mergeSort(A,left,mid);
  mergeSort(A,mid,right);
  con=merge(A,left,mid,right);
  }
  return con;
}

int merge(int *A,int left,int mid,int right){
  int i,j,k=0,L[500000],R[500000],n1,n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=1000000000;
  R[n2]=1000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      count++;
    }
    else{
      A[k]=R[j];
      j=j+1;
      count++;
    }
  }
  return count;
}
