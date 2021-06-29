#include <stdio.h>

main(){

  int i,j;
  int mini,N,count=0,tmp;
  int A[101];

  scanf("%d",&N);

  for(i=1; i<=N; i++){
    scanf("%d",&A[i]);
  }

  for(i=1; i<=N; i++){
    mini = i;

    for(j=i; j<=N; j++){
      if(A[j] < A[mini]){
	mini = j;
      }
    }
      if(A[i] > A[mini]){
	count++;
	tmp = A[i];
	A[i] = A[mini];
	A[mini] = tmp;
      }

  }
  for(i=1; i<=N; i++){
    printf("%d",A[i]);
    if(i!=N){
      printf(" ");
    }
  }
  printf("\n%d\n",count);

  return 0;

}
