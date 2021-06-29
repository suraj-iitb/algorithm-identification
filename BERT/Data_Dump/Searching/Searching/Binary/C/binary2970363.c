#include<stdio.h>
#define NM 1000000
#define QM 50000
#define NOT_FOUND -1

int binarySearch(int *A,int key,int length){
  
  int mid,left = 0,right = length;
  
  while(left < right){
    mid = (left + right)/2;
    if(key == A[mid]) return mid;
    if(key > A[mid]) left = mid +1;
    else if(key < A[mid]) right = mid;
  }
  return NOT_FOUND;
}
  

int main(){

  int i,j,count=0,x,y,A[NM],B[QM],k;

  scanf("%d",&x);

  for(i=0;i<x;i++) scanf("%d",&A[i]);

  scanf("%d",&y);

  for(i=0;i<y;i++) scanf("%d",&B[i]);

  for(i=0;i<y;i++){

    k = binarySearch(A,B[i],x);
    if(k >= 0) count++;

  }
    

  printf("%d\n",count);

  return 0;
}

