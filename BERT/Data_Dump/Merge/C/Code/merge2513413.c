#include<stdio.h>
#include<stdlib.h>
 
#define MAX 500000
#define INFTY 1000000000
 
void MargeSort(int *,int,int);
void Marge(int *,int,int,int);
 
int count=0;
 
int main(void){
  int n,i,A[MAX];
 
  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d", &A[i]);
 
  MargeSort(A,0,n);
  //for(i=0;i<n;i++) printf("%d", A[i]);
  //printf("\n");
 
  for(i=0;i<n;i++){
    if(i!=n-1) printf("%d ",A[i]);
    else printf("%d\n", A[i]);
  }
  printf("%d\n", count);
 
  return 0;
}
 
void MargeSort(int *A,int left, int right){
  int mid;
 
  if(left+1<right){
    mid=(left+right)/2;
    MargeSort(A,left,mid);
    MargeSort(A,mid,right);
    Marge(A,left,mid,right);
  }
 
}
 
void Marge(int *A,int left, int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int L[n1+1],R[n2+1];
  int i,j,k;
 
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
 
  L[n1]=INFTY; R[n2]=INFTY; i=0; j=0;
 
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    } else {
      A[k]=R[j];
      j++;
    }
    count++;
  }
 
}
