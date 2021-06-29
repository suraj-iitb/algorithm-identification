#include <stdio.h>
#define N 500001
#define INFTY 1000000000
int A[N],l[N],r[N],count=0;
 
void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)l[i]=A[left+i];
  for(i=0;i<n2;i++)r[i]=A[mid+i];
   
  l[n1]=INFTY;
  r[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++,count++){
    if(l[i]<=r[j]){
      A[k]=l[i];
      i++;
    }
    else {
      A[k]=r[j];
      j++;
    }
  }
}
 
void mergesort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}
 
int main(){
  int n,i;
 
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
 
  mergesort(A,0,n);
 
 
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",count);
   
  return 0;
}
