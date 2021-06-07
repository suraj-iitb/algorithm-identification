#include <stdio.h>

int search(int A[],int N,int key){
  int left,right,mid;
  left =0;
  right =N;
  while(left <right){
    mid=(left+right)/2;
    if(key==A[mid])
      return mid;
    else if(key < A[mid])
      right = mid;
    else
      left=mid+1;
  }
  return 0;
}

int main(){
  int i,M,N,key,k=0;
  int A[100000];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&M);
  for(i=0;i<M;i++){
    scanf("%d",&key);
    if(search(A,N,key))
      k++;
      }
  printf("%d\n",k);

  return 0;
}
