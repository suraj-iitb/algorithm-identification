#include<stdio.h>
#include<stdlib.h>

int main(){

  int *A,N,flag=1,B,j,count=0;

  scanf("%d",&N);
  A = (int*)malloc(sizeof(int)*N);
  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }
  
  while(flag){
    flag =0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	B = A[j];
	A[j] = A[j-1];
	A[j-1] = B;
	flag = 1;
	count++;
      }
    }
  }
  printf("%d",A[0]);
  for(j=1;j<N;j++){
  printf(" %d",A[j]);
  }
  printf("\n%d\n",count);
  return 0;
}

