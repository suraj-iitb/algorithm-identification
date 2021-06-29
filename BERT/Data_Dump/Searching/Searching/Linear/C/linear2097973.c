#include <stdio.h>
int main () {

   int s[10000], t[500];
   int n, q, i, j, k = 0;

   scanf ("%d\n", &n);
   for (i = 0; i < n; i++) {
     scanf ("%d\n", &s[i]);
   }

   scanf ("%d\n", &q);
   for (j = 0; j < q; j++) {
     scanf ("%d\n", &t[j]);
   }

   for (i = 0; i < q; i++) {
     for (j = 0; j < n; j++) {
       if (s[j] == t[i]) {
         k++;
         break;
       }
     }
   }

   printf ("%d\n", k);

   return 0;
}
