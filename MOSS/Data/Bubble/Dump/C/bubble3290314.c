#include <stdio.h>
#include <stdlib.h>

int main(){

 int j,N,flag,a,i=0;
 int *A;


  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));
  for(j=0;j<N;j++)
  scanf(" %d",&A[j]);
  
  flag = 1;
 
  while(flag == 1){
      flag = 0;
      for(j=N-1;j>=0;j--){
	
	  if(A[j] < A[j-1]){
	  a = A[j];
	  A[j] = A[j-1];
	  A[j-1] = a;
          flag = 1;
          i++;
          }
         
       }
  }
  for(j=0;j<N;j++){
        printf("%d",A[j]);
        if(j != N-1) printf(" ");
        }
  printf("\n%d\n",i);

  return 0;
}

