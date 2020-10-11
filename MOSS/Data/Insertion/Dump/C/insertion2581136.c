#include<stdio.h>

int main()
{
   int N, a, i, j, tmp;

   scanf("%d", &N);
   int A[N];
   for (i=0; i<N; i++)
      scanf("%d", &A[i]);

   for (i=0; i<N; i++){
      if (i<N-1)
         printf("%d ", A[i]);
      else if (i==N-1)
         printf("%d\n", A[i]);
   }

   for (a=1; a<N; a++){

      for (i=a; i<N; i++){
         tmp = A[i];
         j = i-1;
         while (j>=0 && A[j]>tmp){
            A[j+1] = A[j];
            j--;
         }
      A[j+1] = tmp;

         for (i=0; i<N; i++){
            if (i<N-1)
               printf("%d ", A[i]);
            else if (i==N-1)
               printf("%d\n", A[i]);
         }
      }

   }

   return 0;
}
