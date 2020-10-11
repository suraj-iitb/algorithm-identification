#include <stdio.h>
int main()
{
  int i, j, N, flag=1, temp, c=0;
  int A[100]={};

  scanf("%d",&N);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(j=N-1; j>=i+1;){

  }

  for(i=0; i<N; i++){
    for(j=N-1; j>=i+1; j--){
      if(A[j]<A[j-1]){
	temp = A[j-1];       
	A[j-1] = A[j];
	A[j]= temp;
	c++;
      }
    }
  }

  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
      }

  printf("%d",A[N-1]);

  printf("\n%d\n",c);

  return 0;
}  
