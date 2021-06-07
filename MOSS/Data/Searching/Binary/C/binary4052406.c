#include<stdio.h>
#include<stdbool.h>
bool binarySearch(int[],int,int);
  int main(){
  int count,n,A[100000],m,z,i;
  count=0;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&z);
    if(binarySearch(A,m,z))
      count++;
  }
  printf("%d\n",count);
  return 0;
}
bool binarySearch(int *A,int n,int key){
  int mid;
  int left=0;
  int right=n;
  while(left<right){
    mid=(left+right)/2;
      if(A[mid]==key)
	return true;
      else if(key<A[mid])
	right=mid;
      else
	left=mid+1;
  }
  return false;
}

