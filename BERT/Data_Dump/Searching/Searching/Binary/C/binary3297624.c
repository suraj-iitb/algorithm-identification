#include<stdio.h>
#define N 100000
#define M 50000

int binarySearch(int A[], int n, int key){
  int left = 0,mid,right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key) return 1;
    else if(key < A[mid]) right = mid;
    else left = mid + 1;
  } 
  return 0;
}

int main(){
  int i,n,A[N + 1],q,key,sum = 0;

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&key);
    if(binarySearch(A,q,key)) sum++;
  }
  printf("%d\n",sum);

  return 0;
}

