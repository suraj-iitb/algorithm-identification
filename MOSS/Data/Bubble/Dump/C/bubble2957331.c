#include <stdio.h>
int main()
{
  int N,i,j,k,flag=1,count=0;
  int A[100];
  
  scanf("%d",&N);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  i = 0;

  while(flag){
    flag = 0;
    for(j=N-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
	k = A[j];
	A[j] = A[j-1];
	A[j-1] = k;
	flag = 1;
	count++;
      }
    }
    i++;
  }

  for(i=0; i<N-1; i++){
    printf("%d ",A[i]);
  }
     printf("%d",A[N-1]);
  
    printf("\n");  
    printf("%d\n",count);
  return 0;
}

