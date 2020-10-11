#include <stdio.h>
#include <stdlib.h>

int main(){
  int N,A[100],i,j,temp,count=0;

  scanf("%d",&N);
  if (N<1||N>100){
    printf("N ha 1-100 death.\n");
    exit(1);
  }
  for (i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for (i=1;i<=N;i++){
    for (j=N-1;j>=i;j--){
      if (A[j] < A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
    }
  }

  for (i=0;i<N;i++){
    printf("%d",A[i]);
    if (i<N-1){
      printf(" ");
    } else {
      printf("\n");
    }
  }
  printf("%d\n",count);

  return 0;
}
