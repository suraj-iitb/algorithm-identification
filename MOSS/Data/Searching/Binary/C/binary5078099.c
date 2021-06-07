#include<stdio.h>
#include<stdlib.h>
#define N 10^9

int binarySearch(int,int *,int);

int main(){
  int n,q,*S,*T,i = 0,count = 0;

  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  T = (int *)malloc(sizeof(int) * q);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
  }
  for(i = 0;i < q;i++){
    if(binarySearch(n,S,T[i]) == 0)continue;
    else count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int n,int A[],int key){
  int left = 0,right = n,mid = 0;
  while(left < right){
    mid = (left + right)/2;
    if(key == A[mid])
      return mid;
    if(key > A[mid])
      left = mid + 1;
    else if(key < A[mid])
      right = mid;
  }
  return 0;
}

