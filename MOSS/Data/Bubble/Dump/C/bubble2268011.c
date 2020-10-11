#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,i,j,n,*A,count=0;
  scanf("%d",&N);
  A=(int*)malloc(sizeof(int)*N);
  for(i=0;i<N;i++)
      scanf("%d",&A[i]);
  for(i=0;i<N;i++)
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	count++;
	n=A[j];
	A[j]=A[j-1];
	A[j-1]=n;
      }
    }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1)
      printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
