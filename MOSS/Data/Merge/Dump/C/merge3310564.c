#include <stdio.h>
#define MAX 500000
#define SENTINEL 2000000000
int L[MAX/2+2],R[MAX/2+2];
int count;
void merge(int[],int,int,int,int);
void mergeSort(int[],int,int,int);
int main(){
  int A[MAX],n,i;
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  mergeSort(A,n,0,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i==n-1){
      printf("\n");
      break;
    }
    printf(" ");
  }
  printf("%d\n",count);
  return 0;
}
void merge(int A[],int n,int left,int mid,int right){
  int i,j,k,n1,n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)
    L[i]=A[left+i];
  for(j=0;j<n2;j++)
    R[j]=A[mid+j];
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }else{
      A[k]=R[j];
      j=j+1;
    }
  }
}
void mergeSort(int A[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left + right)/2;
   mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}
