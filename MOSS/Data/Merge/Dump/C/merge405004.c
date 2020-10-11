#include<stdio.h>
#define MAX 500000
int count;
void merge(int left,int mid,int right,int A[]){
  int i,j=0,k;
  int n1 = mid-left;
  int n2 = right-mid;
  int L[n1],R[n2];
  for(i = 0;i<n1;i++)L[i]=A[left+i];
  for(i = 0;i<n2;i++)R[i]=A[mid+i];
  
    L[n1]=R[n2]=999999999;
  i=0;
  for(k = left;k< right;k++){
   count++;
   if(L[i]<=R[j])A[k]=L[i++];
    else A[k]=R[j++];
  }
  
}
void mergeSort(int left,int right,int A[]){
  if(left >= right-1 )return;
  int mid = (left+right)/2;
  mergeSort(left,mid,A);
  mergeSort(mid,right,A);
  merge(left,mid,right,A);
  
}
int main (void){
  int size,A[MAX];
  int i;
  scanf("%d",&size);
  for(i = 0;i<size;i++)scanf("%d",&A[i]);
  mergeSort(0,size,A);
  for(i = 0;i<size;i++){
    if(i==0)printf("%d",A[i]);
    else printf(" %d",A[i]);
  }
  printf("\n%d\n",count);
  
  
  return 0;
}
