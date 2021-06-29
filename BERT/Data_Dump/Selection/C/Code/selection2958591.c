#include<stdio.h>

int main( ){
  int i,j,N,tmp,count=0;
  int A[100],mini;

  scanf("%d",&N);
  if((N > 100) &&(N < 0)){
    printf("N is error\n");
  }
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

 

    for(i = 0; i <= N-1; i++){
      mini = i;
      for(j = i; j <= N-1; j++){
	if(A[j] < A[mini]){
	  mini = j;
	}
      }
      if(mini != i){
	tmp = A[i];
	A[i] = A[mini];
	A[mini] = tmp;
	count++;
      }
    }
  

  for(i = 0; i < N; i++){
    if(i > 0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}















