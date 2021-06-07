#include <stdio.h>
int binarySearch(int A[],int n,int key){
  int left,mid,right;
  left=0;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key){
      return 1;
    }
    else if(key<A[mid]){
      right=mid;
    }
    else 
      left=mid+1;
  }
  return 0;
}
int main(){
  int i,n,q,S[100000],key,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(S,n,key)==1)
      sum++;
  }
  printf("%d\n",sum);
  return 0;
}
