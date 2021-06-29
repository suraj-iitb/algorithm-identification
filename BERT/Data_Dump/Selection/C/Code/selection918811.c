#include<stdio.h>

main(){
  int i,j,N,mini,A[100],count=0,swap;
  
  scanf("%d",&N);
  for(i=0 ; i<N ; i++) scanf("%d",&A[i]);
  
  for(i=0 ; i<N ; i++){
    mini = i;
    for(j=i ; j<N ; j++){
      if(A[j]<A[mini]){
	mini = j;
      }
    } 
    if(mini != i){
      swap = A[i];
      A[i] = A[mini];
      A[mini] = swap;
      count++;
      
    }
  }
  
  for(i=0 ; i<N ; i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
