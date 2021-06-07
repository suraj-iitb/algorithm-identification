#include <stdio.h>

#define NOT_FOUND 0

int binarySearch(int);
int n,A[100000];
int main()
{
  int i,q,count=0,T[50000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(binarySearch(T[i])==1) count++;
  }
  printf("%d\n",count);
  return 0;
}
int binarySearch(int key)
{
  int left=0,right=n,mid;
  while(left<right){
    mid = (left+right)/2;
    if(A[mid]==key){
      return 1;
    }
    else if(key<A[mid]){
      right = mid;
    }
    else left = mid+1;
  }
  return NOT_FOUND;
}
