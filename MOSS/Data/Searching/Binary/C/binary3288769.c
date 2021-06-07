#include<stdio.h>
int A[100000],n;
int binarySearch(int key);

int main(){
  int i,q,key,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(key)){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}
int binarySearch(int key){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key){
      return 1;
    }
    else if(key<A[mid]){
      right=mid;
    }
    else{
      left=mid+1;
    }
  }
  return 0;
}

