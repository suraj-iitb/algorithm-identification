#include<stdio.h>

int main( ){
  int i,j,N,flag,tmp,count=0;
  int A[100];

  scanf("%d",&N);
  if((N > 100) &&(N < 0)){
    printf("N is error\n");
  }
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

 
  flag = 1;
  while(flag){
    flag = 0;
    for(i = N-1; i > 0; i--){
      if(A[i]<A[i-1]){
	tmp = A[i];
	A[i]=A[i-1];
	A[i-1]=tmp;
	flag = 1;
	count++;
      }
    }
  }

  for(j = 0; j < N; j++){
    if(j > 0){
      printf(" ");
    }
    printf("%d",A[j]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

