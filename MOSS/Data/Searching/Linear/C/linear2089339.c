#include<stdio.h>

int main()
{
   int n, q, i, j, c=0;
   int s[10000], t[500];

   scanf("%d", &n);
   for(i=0; i<n; i++) scanf("%d", &s[i]);

   scanf("%d", &q);
   for(i=0; i<n; i++) scanf("%d", &t[i]);

   for(i=0; i<q; i++) {
      for(j=0; j<n; j++) {
         if(s[j] == t[i]) {
            c++;
            break;
         }
      }
   }
   printf("%d\n", c);

   return 0;
}

   
