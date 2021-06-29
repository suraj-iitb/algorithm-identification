#include<stdio.h>

int selectionSort(int A[], int N)
{
   int i, j, minj, temp, a=0;

   for(i=0; i<N-1; i++) {
      minj = i;
      for(j=i; j<N; j++) {
         if(A[j]<A[minj]) minj = j;
      }
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      if(i != minj) a++;
   }
   return a;
}

int main()
{
   int a, N, A[100], i;

   scanf("%d", &N);
   for(i=0; i<N; i++) scanf("%d", &A[i]);
   a = selectionSort(A, N);

   for(i=0; i<N; i++) {
      if(i>0) printf(" ");
      printf("%d", A[i]);
   }
   printf("\n");
   printf("%d\n", a);

   return 0;
}

   
