#include<stdio.h>
#define M 500000
#define SEN 2000000000
void merge(int *,int,int,int,int);
void mergeSort(int *,int,int,int);
int L[M/2+2],R[M/2+2];
int cnt=0;
int main(){
int A[M];
 int i,n;
 scanf("%d",&n);
 for(i=0;i<n;i++){
   scanf("%d",&A[i]);
 }
 mergeSort(A,n,0,n);
 for(i=0;i<n;i++){
   if(i!=0)printf(" ");
   printf("%d",A[i]);
      }
 printf("\n");
 printf("%d\n",cnt);
 return 0;
}
void merge(int *A,int n,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=R[n2]=SEN;
  i=0,j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }}
}
void mergeSort(int *A,int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}