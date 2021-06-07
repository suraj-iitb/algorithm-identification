#include<stdio.h>

int main(){
  int i,n,A[100001],q,key,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(n,A,key)!=0)sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int binarySearch(int n,int A[],int key){
  int left = 0;
  int right = n;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key)return 1;
    else if(key<A[mid])right = mid;
    else left=mid+1;
  }
  return 0;
}
