#include<stdio.h>

int main () {

   int n, i, flag, swap;
   int a[100] = {0};
   int count = 0;

   scanf("%d", &n);

   for(i = 0; i < n; i++){
      scanf("%d",&a[i]);
   }

   flag = 1;

   while(flag){
      flag = 0;

      for(i = n-1; i > 0; i--){
         if(a[i] < a[i-1]){
            swap = a[i];
            a[i] = a[i-1];
            a[i-1] = swap;
            flag = 1;
            count++;
         }
      }
   }

   for(i = 0; i < n; i++){
      if(i == n-1){
         printf("%d\n",a[i]);
      } else {
         printf("%d ", a[i]);
      }
   }

   printf("%d\n", count);

   return 0;

}

     
