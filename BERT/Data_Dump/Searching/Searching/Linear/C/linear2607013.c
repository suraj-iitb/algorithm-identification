#include<stdio.h>

int main()
{
   int i, j, n, q, sum=0;
   int S[10000], T[10000];

   scanf("%d", &n);
   for (i=0; i<n; i++)
      scanf("%d", &S[i]);

   scanf("%d", &q);
   for (i=0; i<q; i++)
      scanf("%d", &T[i]);

   for (j=0; j<q; j++){
      i = 0;
      while (S[i]!=T[j])
         i++;
      if (i<n)
         sum++;
   }

   printf("%d\n", sum);

   return 0;
}
