#include<stdio.h>
#include<stdlib.h>
#define N 20000
#define K 10000

int main(){
  int n,i;
  int C[K+1];
  unsigned short *A,*B;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for( i=0 ; i<=K ; i++){
    C[i]=0;
  }

  for( i=0 ; i<n ; i++ ){
   scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
  }

  for( i=1 ; i<=K ; i++){
    C[i] = C[i] + C[i-1];
  }

  for( i=1 ; i<=n ; i++ ){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
 
   for ( i=1 ; i<=n ; i++ ){
   if(i > 1) printf(" ");
     printf("%d",B[i]);
  }
  printf("\n");

  return 0;
} 
