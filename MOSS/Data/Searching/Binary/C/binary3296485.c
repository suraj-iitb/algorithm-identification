#include <stdio.h>
#define N 1000000

int binarySearch(int A[N],int n, int key){
  int left=0;
  int right=0;
  int mid;
  right = n;
  while(left<right){
    mid = (left+right)/2;
    if(A[mid] == key){
      return 1;
    }
    if(key < A[mid]){
      right = mid;
    }
    else left = mid + 1;
  }
  return 0;
}

int main(){
  int i,n,q,k,sum=0,A[N];
  scanf("%d" ,&n);
  for(i=0 ; i<n ; i++){
    scanf("%d" ,&A[i]);
  }
  scanf("%d" ,&q);
  for(i=0 ; i<q ; i++){
    scanf("%d" ,&k);
    if (binarySearch(A,n,k)) sum++;
  }
  printf("%d\n" ,sum);
  return 0;
}




