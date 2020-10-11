#include <stdio.h>

int main()
{
  int A[100],i,j,N,a=0,n=0,flag=1;
  
  scanf("%d",&N);
  
  for(i=0; i<N; i++){
  scanf("%d",&A[i]);
  }

  while(flag)
    {
      flag = 0;
      
      for(j = N-1;j>=1; j--){
	if(A[j] < A[j-1]){
	  a = A[j];
	  A[j] = A[j-1];
	  A[j-1] = a;
	  n++;
	  flag = 1;
	}
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
