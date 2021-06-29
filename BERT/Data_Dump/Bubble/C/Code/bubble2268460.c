#include <stdio.h>
#include <stdlib.h>

int main(){
  int N,*A,i,flag,a,count=0;

  scanf("%d",&N);
  A=(int*)malloc(N*sizeof(int));
  for(i=0;i<N;i++)  scanf("%d",&A[i]);
  flag=1;
  while(flag){
    flag=0;
    for(i=N-1;i>0;i--){
      if(A[i]<A[i-1]){
	a=A[i];
	A[i]=A[i-1];
	A[i-1]=a;
	count++;
	flag=1;
      }
    }
  }
  printf("%d",A[0]);
  for(i=1;i<N;i++)printf(" %d",A[i]);
  printf("\n%d\n",count);
  free(A);
  return 0;
}
