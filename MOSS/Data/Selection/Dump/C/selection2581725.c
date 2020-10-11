#include<stdio.h>

int main()
{
   int A[100], N, i, j, minj, tmp, sw;

   scanf("%d", &N);
   for (i=0; i<N; i++)
      scanf("%d", &A[i]);

   sw = 0;

   for (i=0; i<N; i++){
      minj = i;
      for (j=i; j<N; j++){
         if (A[j]<A[minj])
            minj = j;
      }
      tmp = A[minj];
      A[minj] = A[i];
      A[i] = tmp;
      if (i!=minj)
         sw++;
   }

   for (i=0; i<N; i++){
      if (i>0)
         printf(" ");
      printf("%d", A[i]);
   }
   printf("\n");
   printf("%d\n", sw);

   return 0;
}
