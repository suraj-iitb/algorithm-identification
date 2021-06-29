#include<stdio.h>
#include<stdlib.h>

int main(){
  int *A;
  int flag=1,N,i,j,a,count=0;
  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));
  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag = 0;
    for(j = N-1;j >= 1;j--){
      if(A[j] < A[j-1]){
	a = A[j-1];
	A[j-1]=A[j];
	A[j]=a;
	count++;
	flag = 1;
      }
    }
  }
  for(i = 0;i < N;i++){
    printf("%d",A[i]);
    if(i != N-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

