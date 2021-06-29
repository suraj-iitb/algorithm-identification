#include<stdio.h>

int main() {
   int n, q, i, j, key, a;
   int s[10000];
   int t[500];
   int count = 0;

   scanf("%d\n", &n);
   for (i = 0; i < n; i++)
	   scanf("%d", &s[i]);

   scanf("%d\n", &q);
   for (i = 0; i < q; i++)
	   scanf("%d", &t[i]);

   for (i = 0; i < q; i++) {
	   a = 1;
	   key = t[i];
	   j = 0;
	   while (s[j] != key && j != n) {
		   j++;
	   }
	   if (j == n)
		   a = 0;
	   if (a == 1)
		   count++;

   }
   printf("%d\n", count);

}
