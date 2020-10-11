#include <stdio.h>

int main() {
  int flg,N,v,k=0;
  int i,j;
  int A[100];

  scanf("%d", &N);

  for ( i = 0; i < N; i++) {
    /* code */
    scanf("%d", &A[i]);
  }

  flg=1;
  while (flg==1) {
    /* code */
  flg=0;
  for ( j = N-1; j >= 1 ; j--) {
    /* code */
    if(A[j]<A[j-1]){

      v=A[j];
      A[j]=A[j-1];
      A[j-1]=v;
      k++;
      flg=1;

    }
  }
}
    printf("%d", A[0]);

  for ( i = 1; i < N; i++) {
    /* code */

   printf(" %d", A[i]);
  }
  printf("\n");
  printf("%d\n", k);

  return 0;
}

