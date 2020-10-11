#include <stdio.h>

int selectionSort (int A[], int N)
{
   int i, j, minj, s, count;

   count = 0;

   for (i = 0; i < N-1; i++) {
      minj = i;
      for (j = i; j < N; j++) { 
         if (A[j] < A[minj]) {
            minj = j;
         }
      }

      s = A[i];
      A[i] = A[minj];
      A[minj] = s;

      if (i != minj) {
         count++;
      }
   }

   return count;
}
      

int main ()
{
   int N, A[100];
   int minj, i, c;

   scanf("%d", &N);
   for (i = 0; i < N; i++) {
      scanf("%d", &A[i]);
   }

   c = selectionSort(A, N);

   for (i = 0; i < N; i++) {
      if (i == 0) {
         printf("%d", A[i]);
      } else {
         printf(" %d", A[i]);
      }
   }

   printf("\n");
   printf("%d\n", c);

   return 0;
}

         
