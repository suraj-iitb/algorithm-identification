#include<stdio.h>
#define MAX 1000000
int binarySearch(int);

int A[MAX],n;

int main(){
  int q,i,x,cnt=0;

  scanf("%d",&n);
  for(i=0;i <= n-1;i++)scanf("%d",&A[i]);

  scanf("%d",&q);
  for(i=0;i <= q-1;i++){

    scanf("%d",&x);
    if(binarySearch(x)){
      cnt++;
    }}
  printf("%d\n",cnt);
  return 0;
}

int binarySearch(int key){
  int left=0,right=n,mid;
  while(right>left){
    mid=(right+left)/2;
    if(key == A[mid]){
      return 1;
    }
    if(key > A[mid]){
      left = mid +1;
    }

    else if(key < A[mid])right=mid;
  }
  return 0;
}

    

