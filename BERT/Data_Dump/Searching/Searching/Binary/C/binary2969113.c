#include <stdio.h>
#define NOT_FOUND -1
int n,q;

int main(){
  int i,a,count=0;
  
  scanf("%d",&n);
  int s[n];

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  int t[q];

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    a = binarySearch(s,t[i]);
    if(a != -1){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
  
}

int binarySearch(int *A,int key){
  int left=0,right=n,mid;
  while(left<right){
    mid = (left+right)/2;
    if(key == A[mid]){
      return mid;
    }
    if(key > A[mid]){
      left=mid+1;
    }
    else if(key < A[mid]){
      right = mid;
    }
  }
  return NOT_FOUND;
}

