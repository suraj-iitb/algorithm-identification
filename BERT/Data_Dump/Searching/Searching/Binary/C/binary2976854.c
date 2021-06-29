#include<stdio.h>
#define NOT_FOUND 0
int A[100000];
int n;
int binarySearch(int key){
  int mid,left=0,right = n;
  while(left<right){
    mid = (left + right) /2;
    if(A[mid]==key){
      return 1;
    }else if(key<A[mid]){
      right = mid;
    }else {
      left = mid + 1;
    }
  }
  return NOT_FOUND;
}
int main(){
  int i,key,a,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&key);
    if(binarySearch(key)) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}
