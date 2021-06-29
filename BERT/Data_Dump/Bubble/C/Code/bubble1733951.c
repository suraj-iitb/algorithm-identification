#include <stdio.h>

int main()
{
  int flag=1, n, temp;
  int A[100];   //Array
  int i, count=0;   //loop counter variable

  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ) scanf("%d", &A[i]);

  while( flag ){
    flag = 0;
    for( i = n-1 ; i >= 1 ; i-- ){
      if( A[i] < A[i-1] ){
	temp = A[i-1];
	A[i-1] = A[i];
	A[i] = temp;
	flag = 1;
	count++;
      }
    }
  }
  
  for( i = 0 ; i < n ; i++ ){
    printf("%d", A[i]);
    if( i != (n-1) ) printf(" ");
  }

  printf("\n%d\n", count);

  return 0;
}
