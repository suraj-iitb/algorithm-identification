#include<stdio.h>

int main()
{
   int N, i, j, temp, count=0;
   int A[100];

   scanf("%d", &N);

   for (i=0; i<N; i++)
      scanf("%d", &A[i]);

   for (i=0; i<N-1; i++){
      for (j=N-1; j>=i+1; j--){
         if (A[j]<A[j-1]){
            temp = A[j];
            A[j] = A[j-1];
            A[j-1] = temp;
            count++;
         }
      }
   }

   for (i=0; i<N; i++){
      if (i>0)
         printf(" ");
      printf("%d", A[i]);
   }
   printf("\n");

   printf("%d\n", count);

   return 0;
}
