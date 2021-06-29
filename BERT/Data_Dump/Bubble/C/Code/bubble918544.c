#include<stdio.h>
void swap(int * , int * );

main()
{
  int i,j,A[100];
  int N,count=0;
  scanf("%d",&N);
  for(i=0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<N ; i++){
    for(j=N-1; j>0 ; j--){
      if(A[j] < A[j-1]){
	swap(&A[j],&A[j-1]);
	count++;
      }
    }
  }
  
  for(i=0 ; i<N ; i++){
    if(i == N-1){
      printf("%d\n",A[i]);
      break;
    }
    printf("%d ",A[i]);
  }
  printf("%d\n",count);
  return 0;
}

void swap(int *a , int *b){

  int change;
  change = *a;
  *a = *b;
  *b = change;
}
