#include <stdio.h>

void selectionSort(int A[], int N) {
   int i, j;
   int tmp, minj;
   int c = 0;
   for (i = 0; i < N; i++) {
       minj = i;
       for (j = i; j < N; j++) {
           if (A[j] < A[minj])
               minj = j;
       }

       if (i != minj) {
           tmp = A[i];
           A[i] = A[minj];
           A[minj] = tmp;
           c++;
       }
   }
   for (i = 0; i < N; i++) {
       printf("%d", A[i]);
       printf((i == N-1) ? "\n%d\n" : " ", c);
   }
}

int main()
{
   int i;
   int N, A[101];

   scanf("%d", &N);

   for (i = 0; i < N; i++) {
       scanf("%d", &A[i]);
   }

   selectionSort(A, N);

   return 0;
}
