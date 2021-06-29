#include<stdio.h>

int main () {

   int s[10001] = {0};
   int t[501] = {0};
   int x, y, i, j;
   int count = 0;

   scanf("%d", &x);

   for(i = 0; i < x; i++){
      scanf("%d", &s[i]);
   }

   scanf("%d", &y);

   for(i = 0; i < y; i++){
      scanf("%d", &t[i]);
   }

   for(i = 0; i < y; i++){
      for(j = 0; j < x; j++){
         if(s[j] == t[i]){
            count++;
            break;
         }
      }
   }

   printf("%d\n", count);

   return 0;

}
