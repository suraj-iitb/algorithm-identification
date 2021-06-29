#include <stdio.h>

int bubbleSort(int A[], int N)
{
  int flag = 1, t,j, i=0, sw=0;
  while (flag) {		  
      flag =0;
      for (j= N-1; j>=i+1; j--){
	    if ( A[j] < A[j-1] ){
	      t = A[j]; A[j] = A[j-1]; A[j-1] = t;
	      sw++;
	      flag=1;
	    }
      }
      i++;
  }
  return sw;
}


void print(int A[], int N, int sw){
  int i;
  for ( i = 0; i < N; i++ ){
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);
}

int main( void )
{
  int A[100], n, i, sw=0;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  sw=bubbleSort(A,n);

  print(A,n,sw);
  
  return 0;
}

  

