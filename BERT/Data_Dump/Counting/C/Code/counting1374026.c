#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

main()
{
  unsigned short *A, *B;
  int C[VMAX+1]; //カウント用
  int i, j, n;

  scanf("%d", &n);
  A = malloc(sizeof(short)*n + 1);
  B = malloc(sizeof(short)*n + 1);

  for(i=0; i<=VMAX; i++) C[i]=0;

  /* Aの読込み & Cにそれぞれの数の出現数をカウント */
  for(i=0; i<n; i++)
    {
      scanf("%hu", &A[i+1]);
      C[A[i+1]]++;
    }

  /* C[i]にi以下の数の出現数を記録(handout 6th lecture p17) */
  for(i=1; i<=VMAX; i++) C[i] = C[i] + C[i-1];

  /* Counting Sort */
  for(j=1; j<=n; j++)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }

  /* print */
  for(i=1; i<=n; i++)
    {
      printf("%d", B[i]);
      if(i != n)
	{
	  printf(" ");
	}
    }
  printf("\n");

  return 0;
}
