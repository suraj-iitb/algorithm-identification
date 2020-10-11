#include<stdio.h>

int main()
{
 int i, j, k, m, kosuu, box, a[101];

 scanf("%d", &kosuu);
 for(i = 1;i <= kosuu;i++){
   scanf("%d", &a[i]);
 }
 for(m = 1;m < kosuu;m++) {
   printf("%d ", a[m]);
 }
 printf("%d\n", a[kosuu]);
 
 for(i = 2;i <= kosuu;i++) {
   for(j = 1;j <= i-1;j++) {
     if (a[i] < a[j]) {
       box = a[i];
       for(k = i - 1;k >= j;k--) {
       a[k + 1] = a[k];
       }
       a[j] = box;
     }
   }
   for(m = 1;m < kosuu;m++) {
     printf("%d ", a[m]);
   }
   printf("%d\n", a[kosuu]);
 }

 return 0;
}
