#include <stdio.h>

void insertionSort(int A[], int N) {
   int i, j;
   int tmp;

   for (i = 1; i < N; i++) {
       for (j = 0; j < N; j++) {
           printf("%d", A[j]);
           if (j != N-1)
               printf(" ");
           else
               printf("\n");
       }

       tmp = A[i];
       j = i-1;

       while (j >= 0 && A[j] > tmp) {
           A[j+1] = A[j];
           j--;
       }
       A[j+1] = tmp;
   }
}

int main() {
   int N, A[1001];
   int i;

   scanf("%d", &N);

   for (i = 0; i < N; i++)
       scanf("%d", &A[i]);

   insertionSort(A, N);

   for (i = 0; i < N; i++) {
       printf("%d", A[i]);
       if (i != N-1)
           printf(" ");
       else
           printf("\n");
   }

   return 0;
}
