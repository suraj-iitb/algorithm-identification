#include <stdio.h>

int main(){
  int N,i,a,flag,A[100],c=0;

  scanf("%d",&N);

  for(i=0; i < N; i++){
    scanf("%d",&A[i]);
  }

  flag = 1;

  while(flag){
    
    flag = 0;

    for(i=N-1; i > 0; i--){
      if(A[i] < A[i-1]){
	a = A[i];
	A[i] = A[i-1];
	A[i-1] = a;
	c += 1;
	flag = 1;
      }
    }

  }

  for(i=0; i < N; i++){
    printf("%d",A[i]);
    if(i != N-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}

