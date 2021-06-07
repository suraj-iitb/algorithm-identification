#include<stdio.h>

int main() {

   int S[100000], T[50000];
   int i, j, n, q, rig, mid;
   int c = 0;
   int lef = 0;

   scanf("%d", &n); 
   for (i = 0; i < n; i++) {
      scanf("%d", &S[i]);
   }

   scanf("%d", &q); 
   for (i = 0; i < q; i++) {
      scanf("%d", &T[i]);
   }

   rig = n;
   for (i = 0; i < q; i++) {
      while (lef < rig) {
         mid = (lef + rig) / 2;
         if (S[mid] == T[i]) {
            c++;
            break;
         } else if (T[i] < S[mid]) {
            rig = mid;
         } else {
            lef = mid + 1;
         }
      }
      rig = n;
      lef = 0;
   }
   printf("%d\n", c);

   return 0;
}
