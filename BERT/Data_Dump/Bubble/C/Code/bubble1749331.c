#include<stdio.h>

int main()
{
  
  int i,j,tmp,count=0,N,flag;
  int A[100];

  scanf("%d",&N);
  
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  
 
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=0;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	count++;
      }
    }
  }
   for(i=0;i<N;i++){
      printf("%d",A[i]);
    if(i != N-1) printf(" ");   
    }  
   printf("\n");

  printf("%d\n",count);

  return 0;
}
