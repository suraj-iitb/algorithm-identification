#include <stdio.h>
  
#define N 500000
  
void merge(int*, int, int);
  
int A[N],n,count=0;
int temp[N];
  
  
int main(){
  
  int i,j;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
    merge(A,0,n-1);
  
  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d",A[n-1]);
  printf("\n%d\n",count);
  
  return 0;
}
  
  
void merge(int A[],int left,int right){
  
  int mid,i,j,k;
  
  if(left>=right) return;
  
  mid=(left+right)/2;
  
  merge(A,left,mid);
  merge(A,(mid+1),right);
  
  for(i=left;i<=mid;i++){
    temp[i]=A[i];
  }
  
  for(i=(mid+1),j=right;i<=right;i++,j--){
    temp[i]=A[j];
  }
  
  i=left;
  j=right;
  
  for(k=left;k<=right;k++){
  
    if(temp[i]<=temp[j]) A[k]=temp[i++];
    else A[k]=temp[j--];
  
    count++;
}
  
}
