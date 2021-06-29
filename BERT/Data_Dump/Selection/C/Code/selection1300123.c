#include<stdio.h>
#include<stdlib.h>
#define N 100

main(){
  int A[N],a,i,j,n,minj,count=0;

  scanf("%d",&n);
  if( n > N )
    exit(1);

  for( i=0 ; i < n ; i++)
    scanf("%d",&A[i]);

  for( i = 0 ; i < n ; i++ ){
    minj = i;
    for( j = i ; j < n ; j++ ){
      if( A[j] < A[minj] )
	minj = j;
    }
    if( minj > i){
      a = A[i];
      A[i] = A[minj];
      A[minj] = a;
      count++;
    }
  }
     
    
  for( i = 0 ; i < n ; i++){
    printf("%d",A[i]);
    if ( i != n - 1)
      printf(" ");
  }
  printf("\n%d\n",count);
   
  return 0;
  
}
