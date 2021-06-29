#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 2000001
#define VMAX 10000



int main()
{
  int *A, *B;
  int *C;
  int n, i, j,m;

  scanf("%d", &n);

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);

  /* your code */

for(i=1;i<=n;i++)
{
scanf("%d",&A[i]);
}

m=A[1];

for(i=2;i<=n;i++)
{
if(A[i]>m)m=A[i];
}

C = malloc(sizeof(int)*(m+1));

for(i=0;i <= m;i++)
{
C[i] = 0;
}

for(j=0;j<100;j++)
{
    i++;
}

for(j = 1; j <= n; j++)
{
 C[A[j]]++;
}

for(i = 1; i <= m; i++)
  {
    C[i] = C[i] + C[i - 1];
  }

  for(j = n; j >= 1; j--)
  {
    B[C[A[j]]] = A [j];
    C[A[j]]--;
  }

  for(j = 1; j <= n; j++)
  {
    printf("%d",B[j]);
    if(j != n)printf(" ");
  }

  printf("\n");

  return 0;
}
