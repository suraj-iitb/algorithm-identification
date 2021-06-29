#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
/*
  void CountingSort(int * ,int *,int);
  int C[VMAX+1];
  int n;
*/
int main()
{
  unsigned short *A, *B;
  int C[VMAX+1];
  int n,i,j,k=0;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=1;i<=n;i++)
    {
      scanf("%hd",&A[i]);
    }

  for(i=1;i<=n;i++)
    {
      if(A[i]>=k)
	{
	  k=A[i];
	}
    }
  // printf("%d\n",k);
  for(j=0;j<=k+1;j++)
    {
      C[j] = 0;
    }
  //C[i] に i の出現数を記録する
  for(i=1;i<=n;i++)
    {
      C[A[i]]++;
    }
  /*
    for(i=0;i<n;i++)
    {
    printf("%d",C[i]);
    }
    printf("\n");
  */
  //C[i] に i 以下の数の出現数を記録する(各要素の出現回数の和を取っていく。累積和)
  for(i=1;i<=k+1;i++)
    {
      C[i]=C[i]+C[i-1];
    }
  // printf("%d\n",C[6]);
  for(j=n;j>=1;j--)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }
  for(i=1;i<=n;i++)
    {
      if(i==n)
	{
	  printf("%d",B[i]);
	}
      else
	{
	  printf("%d ",B[i]);
	}
    }
  printf("\n");
  
  return 0;
}

/*
void CountingSort(A, B, k)
{
  int i,j;
  for(i=0;i<=k+1;i++)
    {
      C[i] = 0;
    }
  //C[i] に i の出現数を記録する
  for(j=0;j<n;j++)
    {
      C[A[j]]++;
    }
    for(i=0;i<n;i++)
    {
      printff("%d",C[i]);
    }
  //C[i] に i 以下の数の出現数を記録する(各要素の出現回数の和を取っていく。累積和)
  for (i = 1 to k)
    {
      C[i] = C[i] + C[i-1];
    }
  //
  for (j = n downto 1)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }
}
*/

