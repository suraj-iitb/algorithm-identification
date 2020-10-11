#include<stdio.h>
#include<stdlib.h>

int main(){

  int N,i,j,flag,box,count = 0;
  int *A;

  scanf("%d",&N);

  A=malloc(sizeof(int)*N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  flag = 1;
  while(flag){
    flag = 0;
    for(j=N-1;j>0;j--)
      if(A[j]<A[j-1]){
	count++;
	box = A[j];
	A[j] = A[j-1];
	A[j-1] = box;
	flag = 1;
      }
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  free(A);

  return 0;
}
