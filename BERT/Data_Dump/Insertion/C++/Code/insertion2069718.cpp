#include <stdio.h>

int main(void)
{

  int i, j, N, v, k;
  int A[100];

  scanf ("%d\n", &N);

  for (i = 0; i < N; i++) {
   scanf ("%d ", &A[i]);
  }

  for (i = 1; i < N+1; i++) {
   v = A[i];
   j = i - 1;

    for (k = 0; k < N; k++) {
        printf("%d", A[k]);
        if (k < N-1) printf(" ");
        else printf("\n");
    }

    while (j >= 0 && A[j] > v) {
     A[j+1] = A[j];
     j--;
     A[j+1] = v;
   }

  
   } 
return 0;
}
