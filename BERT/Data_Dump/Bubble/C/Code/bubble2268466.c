#include<stdio.h>
int main( )
{
  int i, j, temp,count=0;
  int A[100],N;
  scanf("%d",&N);
  for(i=0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i < N-1; i++){
    for(j = N-1; j > i; j--){
      if(A[j]<A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
      }
    }
  }
  for(i = 0; i < N ; i++){
    if(i == N-1){
      printf("%d",A[i]);
    }
   else printf("%d ",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
