#include <stdio.h>
int binarySearch(int A[],int key,int n){
  int i=0;
  int right=n,left=0;
  int mid;

  while(right>left){
    mid = (right + left)/2;
    if(A[mid]==key)return 1;
    else if(key<A[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}
int main() {
  int n,q,S[100000],T[50000],i,key,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) {
    scanf("%d",&key);
    count += binarySearch(S,key,n);
  }
  printf("%d\n",count);
  return 0;
}

