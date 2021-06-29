#include <stdio.h>
#define VMAX 10000

int main()
{
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);
  int A[n], B[n];
  for (i = 0; i <= VMAX; i++)
      C[i] = 0;

  for(i=0; i<n; i++) {
    scanf("%d", &A[i+1]);
    /*C[i] に i の出現数を記録する*/
        C[A[i+1]]++;
  }

  /*C[i] に i 以下の数の出現数を記録する*/
  for (i = 1; i <= VMAX; i++)
     C[i] = C[i] + C[i-1];

 for (j = n; j >= 1; j--) {
     B[C[A[j]]] = A[j];
     C[A[j]]--;
   }

  for(i=1; i<=n; i++) {
    if(i==n) printf("%d", B[i]);
    else printf("%d ", B[i]);
  }
  printf("\n");

  return 0;
}

