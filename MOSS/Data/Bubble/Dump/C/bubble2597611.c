#include<stdio.h>
int main()
{
   int n, v;
   int A[150];
   int i = 0,
	   s = 0;
   int flag;

   scanf("%d", &n);
   while (i < n) {
      scanf("%d", &A[i]);
      i++;
   }

   flag = 1;
   while (flag) {
      flag = 0;
      for (i = n - 1; i > 0; --i) {
         if (A[i] < A[i - 1]) {
            v = A[i];
			A[i] = A[i - 1];
			A[i - 1] = v;
			s = s + 1;
			flag = 1;
         }
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
