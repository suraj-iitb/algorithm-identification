#include <stdio.h>
#define SENTINEL 1000000000;
int A[500000];
int L[500000],R[500000];
int count=0;
void merge(int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
   
  for(i=0;i<n1;i++)
    {
      L[i]=A[left+i];
    }
  for(i=0;i<n2;i++)
    {
      R[i]=A[mid+i];
    }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      count++;
      if(L[i]<=R[j])
    {
      A[k]=L[i];
      i++;
    }
      else
    {
      A[k]=R[j];
      j++;
    }
    }
}
 
void mergesort(int left,int right){
  int mid;
  if(left+1<right)
    {
      mid=(left+right)/2;
      mergesort(left,mid);
      mergesort(mid,right);
      merge(left,mid,right);
    }
  return 0;
}
 
main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
 
  mergesort(0,n);
 
  for(i=0;i<n;i++)
    {
      printf("%d",A[i]);
      if(i<n-1)
    {
      printf(" ");
    }
    }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
