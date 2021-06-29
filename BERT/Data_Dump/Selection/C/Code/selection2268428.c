#include<stdio.h>
#include<stdlib.h>

int main(){

  int i,N,j,minj,box,count = 0;
  int A[100];

  scanf("%d",&N);

  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
	minj = j;
    }
    if(i != minj){
      box = A[i];
      A[i] = A[minj];
      A[minj] = box;
      count++;
    }
  }
  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);

  printf("%d\n%d\n",A[i],count);

  return 0;
}
