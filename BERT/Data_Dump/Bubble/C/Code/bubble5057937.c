#include <stdio.h>

int main( )
{
  int A[100],i,j,N,tmp,count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(j=0;j<N-1;j++){
    for(i=N-1;i>j;i--){
      if(A[i]<A[i-1]){
	tmp = A[i-1];
	A[i-1] = A[i];
	A[i] = tmp;
	count++;
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

