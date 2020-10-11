#include <stdio.h>

main(){
  int N;
  scanf("%d",&N);
  int A[N+1], i, j, hozon,count=0;

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<N; i++){
    for(j=N-1; j>i; j--){
      if(A[j-1] > A[j]){
	hozon = A[j];
	A[j] = A[j-1];
	A[j-1] = hozon;
	count++;
      }
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
