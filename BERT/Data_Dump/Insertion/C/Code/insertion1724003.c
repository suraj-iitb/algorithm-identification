  #include<stdio.h>
#include<stdlib.h>
#define max 100


int main()
{
  int i,N,v,j,k;
  int A[max];

  scanf("%d",&N);
   if( N < 1 || 100 < N ) exit(2);

   for( i = 0 ; i < N ; i++ ){
     scanf("%d",&A[i]);
     if( A[i] < 0 || 1000 < A[i] ) exit(3);
   }

for( k = 0 ; k < N-1 ; k++)
      printf("%d ",A[k]);
 printf("%d\n",A[k]);

  for( i = 1 ; i <= N-1 ; i++ ){

    v = A[i];
    j = i-1;
    while( j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
}   
for( k = 0 ; k < N-1 ; k++)
      printf("%d ",A[k]);
 printf("%d\n",A[k]);
  }

   return 0;
}
