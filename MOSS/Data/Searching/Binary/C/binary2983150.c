#include<stdio.h>
int binarySearch(int *,int,int);
int main(){
  int n,q,b,count=0;
  int A[100000];
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&b);
    if(0 <= binarySearch(A,b,n))count++;
  }
  printf("%d\n",count);
  return 0;
}
int binarySearch(int *A,int key,int n){
  int NOT_FOUND=-1;
  int left=0,right=n,mid;
 
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key)return mid;
    else if (key < A[mid])right=mid;
    else left=mid+1;
  }
  return NOT_FOUND;
}

