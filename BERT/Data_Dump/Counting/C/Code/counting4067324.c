/* 計数ソート */
#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

int main()
{
  unsigned short *A, *B;
  int C[VMAX+1] = {0};
  int n, i;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for( i = 1; i<=n; i++ )
    scanf("%u", &A[i]);

  /* 計数ソートを用いて昇順にソート */
  
  for( i = 1; i<=n; i++ )        /* C[i]に i の出現数を記録 */
    C[ A[i] ]++;

  for( i = 1; i<=VMAX; i++ )
    C[i] += C[i-1];             /* C[i]に i 以下の数の出現数を記録 */

  for( i = n; i>=1; i-- )
    {
      B[ C[ A[i] ] ] = A[i];
      C[ A[i] ]--;
    }

  /* 結果を出力 */
  for( i = 1; i<=n; i++ )
    {
      printf("%u", B[i]);
      if( i != n )
	printf(" ");
    }
  printf("\n");
  
  return 0;
}

