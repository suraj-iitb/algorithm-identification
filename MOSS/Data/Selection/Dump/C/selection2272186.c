#include <stdio.h>

int main ()
{
  int A[100],i,j,N,a=0,n=0,minj;
  
  scanf("%d",&N);
  
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<N-1; i++){
    minj = i;
    
    for(j = i;j<N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(minj!=i){
      a = A[i];
      A[i] = A[minj];
      A[minj] = a;
      n++;
    }
      
  }

  for(i=0; i<N; i++){
    printf("%d",A[i]);
if(i!=N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",n);
  return 0;
}
