#include <stdio.h>

int main(){

  int i ;
  int length ;
  scanf("%d" , &length);

  int A[length];

  for ( i = 0 ; i < length ; i++){
    scanf("%d" , &A[i]) ;
  }

  int minj;
  int j;
  int tmp;
  int counter = 0;

  for( i = 0 ; i < length ; i++){
    minj = i;

    for ( j = i ; j < length ; j++){
      if (A [j] < A[minj]){
	minj = j;
      }
    }

    if(A[i] != A[minj]){
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      counter++;
    }
    
  }



  

  for(i = 0 ; i < length ; i++){
    printf("%d",A[i]);
    if(i < length - 1)printf(" ");
  }
  
  printf("\n");

  printf("%d\n",counter);

  return 0;
  
  
}

