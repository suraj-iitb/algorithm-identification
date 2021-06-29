#include<stdio.h>
 
 
void merge(int * ,int , int ,int);
void mergeSort(int*,int,int);
 
#define N 500000
 
int count=0;
 
int main(){
 
  int S[N],n,i;
 
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
 
   mergeSort(S,0,n);
 
 for(i=0;i<n-1;i++)printf("%d ",S[i]);
 
  printf("%d\n",S[i]);
  printf("%d\n",count);
 
  return 0;
}
 
void merge(int *A , int left, int mid, int right){
 
  int L[N],R[N],n1,n2,i,j,k;
 
  n1=mid-left;
  n2=right-mid;
 
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
 
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    count++;
  }
 
  
}
 
void mergeSort(int *A,int left, int right){
 
  int mid;
 
  if(left+1<right) {
    mid=(left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }  
   
   
}