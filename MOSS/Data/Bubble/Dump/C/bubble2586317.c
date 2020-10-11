#include<stdio.h>

int main()
{
 int i, j, k, kosuu, box, CGcount = 0, a[101];

 scanf("%d", &kosuu);
 for(i = 1;i <= kosuu;i++){
   scanf("%d", &a[i]);
 }

 for(i = 1;i <= kosuu;i++) {
   for(j = kosuu;j > i;j--) {
     if (a[j] < a[j-1]) {
       box    = a[j-1];
       a[j-1] = a[j];
       a[j]   = box;
       CGcount++;
     }
   }
 }
 for(k = 1;k < kosuu;k++) {
   printf("%d ", a[k]);
 }
 printf("%d\n%d\n", a[kosuu], CGcount);

 return 0;
}
