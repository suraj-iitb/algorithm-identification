#include<stdio.h>
int main()
{
   int n, v, minj;
   int A[150];
   int i = 0,
	   j = 0,
	   s = 0;

   scanf("%d", &n);
   while (i < n) {
      scanf("%d", &A[i]);
      i++;
   }

   for (i = 0; i < n - 1; ++i) {
      minj = i;
	  for (j = i; j < n; ++j) {
         if (A[j] < A[minj])
            minj = j;
	  }
	  if (i != minj) {
		  v = A[i];
		  A[i] = A[minj];
		  A[minj] = v;
		  s = s + 1;
	  }
   }
   for (i = 0; i < n; ++i) {
	   printf("%d", A[i]);
	   if (i != n - 1)
		   putchar(' ');
   }
   putchar('\n');
   printf("%d\n", s);
   return 0;
}
