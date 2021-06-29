#include <stdio.h>

main(){
  int N;
  scanf("%d",&N);
  int A[N+1], i, j, hozon,count=0, min;

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<N; i++){
    min = i;
    for(j=i; j<N; j++){
      if(A[min] > A[j]){
	min = j;
      }
    }
    if(min != i){
	hozon = A[i];
	A[i] = A[min];
	A[min] = hozon;
	count++;
    }
  }

  for(i=0; i<N; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}
