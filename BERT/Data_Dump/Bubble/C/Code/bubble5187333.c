#include <stdio.h>

int main()
{
  int A[100],i,j=0,temp,N,c=0;

  scanf("%d",&N);

  for(i = 0; i < N; i++) scanf("%d",&A[i]);
  
  while(N != j){
    for(i = N - 1; j < i; i--){
      if(A[i] < A[i-1]){
	temp = A[i-1];
	A[i-1] = A[i];
	A[i] = temp;
	c++;
      }
    }
    j++;
  }

  for(i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}

