#include <stdio.h>
#define M 100000
#define N 50000

int binarySearch(int, int *, int);

int main(){
  int n,q,A[M],B[N],i,j,count=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(j=0; j<q; j++){
    scanf("%d",&B[j]);
    if(binarySearch(i,A,B[j])==0) count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarySearch(int n, int *A, int key){
  int left, right, mid;
  left=0;
  right=n;
  while(left<right){
    mid = (left+right)/2;
    if(key == A[mid])return 0;
    if(A[mid] < key)left=mid+1;
    else if(key < A[mid])right=mid;
  }
  return 1;
}

