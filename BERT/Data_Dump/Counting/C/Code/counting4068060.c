#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(unsigned short A[], unsigned short B[], int n);




int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  for( i = 0; i < n; i++){
    scanf("%hu",&A[i+1]);
  }
  CountingSort(A,B,n);
   for( i = 1; i <= n; i++){
     if( i > 1)printf(" ");
     printf("%d",B[i]);
   }
   printf("\n");
  
  



  return 0;
}

void CountingSort(unsigned short A[], unsigned short B[], int n)
{
  int c[VMAX + 1];
  int i;
  int j;
  
  for( i = 0; i <= VMAX; i++)
    c[i] = 0;
  
  for( j = 1; j <= n; j++)
    c[A[j]]++;
  
  for( i = 1; i <= VMAX; i++)
    c[i] = c[i] + c[i-1];
  
  for( j = n; j >= 1; j--){
    B[c[A[j]]] = A[j];
    c[A[j]]--;
  }
  


}

