#include <stdio.h>

int main(void){

   int n, q, m, i, j;

   m = 0;

   scanf("%d", &n);

   int S[n];

   for(i = 0; i < n; i++) {
      scanf("%d", &S[i]);
   }

   scanf("%d", &q);

   int T[q];

   for(i = 0; i < q; i++) {
      scanf("%d", &T[i]);
   }

   for(i = 0; i < q; i++) {
      for(j = 0; j < n; j++) {
         if (T[i] == S[j]){
            m++;
            break;
         }
      }
   }

   printf("%d\n", m);

   return 0;
}
