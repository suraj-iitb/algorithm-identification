#include<stdio.h>

int main()
{
  int i, j, k;   //Loop counter variable
  int A[100];       //Array
  int N;         //Element count
  int v;         //Variable to store temporarily

  scanf("%d", &N);   //input of element count
  
  //error processing
  if( 1 > N || N > 100 ) printf("入力された要素数は範囲外です。\n");
  
  else{
    //input of element
    for( i = 0 ; i < N ; i++ ){
      scanf("%d", &A[i]); 
      //error processing
      if( 0 > A[i] || 1000 < A[i] )
	printf("入力された要素は範囲外です。\n");
    }
    
    for( i = 0 ; i < N ; i++ ){
      printf("%d", A[i]);
      if( i < N-1 ) printf(" ");
    }
    printf("\n");

    //ascending sort
    for( i = 1 ; i <= N-1 ; i++ ){   
      v = A[i];
      j = i - 1;
      while( j >= 0 && A[j] > v ){
	A[j+1] = A[j];
	j--;
	A[j+1] = v;
      }
      //output of intermediate results
      for( k = 0 ; k < N ; k++ ){
	printf("%d", A[k]);
	if( k < N-1 ) printf(" ");
      }
      printf("\n");
    }
  }
  
  return 0;
}
