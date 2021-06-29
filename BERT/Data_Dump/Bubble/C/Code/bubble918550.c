#include<stdio.h>

main(){
  int i,j,A[100],N,count=0,swap;

  scanf("%d",&N);
  for(i=0 ; i<N ; i++)   scanf("%d",&A[i]);
  
  for(i=0 ; i<N-1 ; i++){
    for(j=N-1 ; j>i ; j--){
      if(A[j] < A[j-1]){
	swap = A[j];
	A[j] = A[j-1];
	A[j-1] = swap;
	count++;
      }
    }
  }
  
  for(i=0 ; i<N ; i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}
