#include<stdio.h>
#include<stdlib.h>
#define max 2000001


int main(){
    int  A[max+1],B[max+1];

   int C[max+ 1],n,i;
   
  scanf("%d",&n);

 

  for ( i = 0; i <= max; i++ ) C[i] = 0;

  for ( i = 0; i < n; i++) {
    
    scanf("%d", &A[i + 1]);
    
    C[A[i + 1]]++;
    
  }

  for ( i = 1; i <= max; i++ ) C[i] = C[i] + C[i - 1];

  for( i = 1; i <= n; i++){
    
    B[C[A[i]]] = A[i];
    
    C[A[i]]--;
    
  }

  for( i = 1; i<= n; i++ ){
    
    if ( i > 1)printf(" ");
    
    printf("%d", B[i]);
    
  }
  
  printf("\n");

  return 0;
}

