#include<stdio.h>

int main() {

   int i, j, n, m, flag;
   int A[100];
   int c = 0;

   scanf("%d", &n);

   for (i = 0; i < n; i++) {
      scanf("%d", &A[i]);
   }

   flag = 1;
   while (flag) {
      flag = 0;
      for (i = 1; i < n; i++) {
         if (A[i] < A[i - 1]) {
            m = A[i];
            A[i] = A[i - 1];
            A[i - 1] = m;
            flag = 1;
            c++;
         }
      }
   }
   for (j = 0; j < n; j++) {
      printf("%d", A[j]);
      if(j != n - 1)
         putchar(' ');
   }
   printf("\n");
   printf("%d\n", c);

   return 0;
}

