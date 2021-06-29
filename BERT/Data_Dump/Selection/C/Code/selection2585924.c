#include<stdio.h>

int main()
{
 int i, j, kosuu, a[101], CGcount = 0, min, minnum, box;

 scanf("%d", &kosuu);
 for(i = 1;i <= kosuu;i++){
   scanf("%d", &a[i]);
 }

 for(i = 1;i <= kosuu;i++){
   min = a[i];
   for(j = i + 1;j <= kosuu;j++){
     if(a[j] < min){
       min = a[j];
       minnum = j;
     }
   }
   if(min < a[i]){
      box  = a[i];
      a[i] = min;
      a[minnum]  = box;
      CGcount++;
   }
 }
 
 for(i = 1;i < kosuu;i++){
   printf("%d ", a[i]);
 }
 printf("%d\n%d\n", a[kosuu], CGcount);

 return 0;
} 
