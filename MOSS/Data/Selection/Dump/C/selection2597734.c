#include<stdio.h>

int main (){
   int n, i, j, minj, swap;
   int a[100] = {0};
   int count = 0;


   scanf("%d", &n);

   for(i = 0; i < n; i++){
      scanf("%d", &a[i]);
   }

   for(i = 0; i < n; i++){
      minj = i;
      for(j = i; j < n; j++){
         if(a[j] < a[minj]){
            minj = j;
         }
      }
      if(i != minj){
         swap = a[i];
         a[i] = a[minj];
         a[minj] = swap;
         count++;
      }
   }

   for(i = 0; i < n; i++){
      if(i == n-1){
         printf("%d\n", a[i]);
      } else {
         printf("%d ", a[i]);
      }
   }
  
   printf("%d\n", count);

   return 0;
}
