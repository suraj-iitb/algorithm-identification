#include <stdio.h>
#include <stdlib.h>
#define VMAX 10000
#define NMAX 2000000



int main(){
  //計数ソート
  int n,j,i;
  unsigned short *A, *B;
  int C[VMAX+1];

  scanf("%d", &n);
  //メモリ確保
  A = (unsigned short *)malloc(sizeof(short)*n+1);
  B = (unsigned short *)malloc(sizeof(short)*n+1);



    for(i = 0; i <= VMAX; i++) C[i] = 0;
  /* C[i] に i の出現数を記録する */
    for (i = 0; i < n; i++){
      scanf("%hu",&A[i+1]);
      C[A[i+1]]++;
    }

  /* C[i] に i 以下の数の出現数を記録する*/
  for (i = 1; i <= VMAX; i++) C[i] = C[i] + C[i-1];

  for (j = 1; j <= n; j++) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  //output

  for (i = 1; i <= n; i++){
    if (i == n) printf("%hu\n", B[i]);
    else printf("%hu ", B[i]);
  }

  free(A);
  free(B);

  return 0;
}

