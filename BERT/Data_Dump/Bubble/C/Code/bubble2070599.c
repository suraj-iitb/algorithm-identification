#include <stdio.h>

int main(void)
{

  int i, j, N, c=0, flag =1, temp;
  int A[100];

  scanf ("%d\n", &N);


  for (i = 0; i < N; i++) {
   scanf ("%d ", &A[i]);
  }

 i = 0;
   while (flag) {
    flag = 0;
    for (j = N-1; j >= i+1; j--) {
      if (A[j] < A[j-1]) {
       temp = A[j];
       A[j] = A[j-1];
       A[j-1] = temp;
       c++;
       flag = 1;
      }
    }
   }

   for (i =0; i < N-1; i++) {
      printf("%d ", A[i]);
   }
   printf("%d\n%d\n", A[N-1], c);
   return 0;
}
