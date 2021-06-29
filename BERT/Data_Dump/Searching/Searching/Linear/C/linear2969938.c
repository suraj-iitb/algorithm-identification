#include<stdio.h>
#define NM 10000
#define QM 500
#define NOT_FOUND -1

int linearSearch(int *A,int key,int length){
  int i=0;
  A[length] = key;
  while (A[i] != key) i++;
  if(i == length) return NOT_FOUND;
  return i;
}

int main(){

  int i,j,count=0,x,y,A[NM],B[QM],k;

  scanf("%d",&x);

  for(i=0;i<x;i++) scanf("%d",&A[i]);

  scanf("%d",&y);

  for(i=0;i<y;i++) scanf("%d",&B[i]);

  for(i=0;i<y;i++) {
    k =  linearSearch(A, B[i], x+1);
    if( k >= 0 ) count++;
  }

  printf("%d\n",count);

  return 0;
}
  

