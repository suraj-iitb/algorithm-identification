#include<stdio.h>
int main()
{
   int n, v;
   int A[150];
   int i = 0,
	   j = 0,
	   k = 0;

   scanf("%d", &n);
   while (i < n) {
      scanf("%d", &A[i]);
      i++;
   }

   for (i = 0; i < n; ++i) {
      v = A[i];
	  j = i - 1;
      while (j >= 0 && A[j] > v) {
         A[j + 1] = A[j];
         --j;
      }
      A[j + 1] = v;
      for (k = 0; k < n; ++k) {
         printf("%d", A[k]);
		 if (k != n - 1)
			 putchar(' ');
	  }
	  putchar('\n');
   }
   return 0;
}
