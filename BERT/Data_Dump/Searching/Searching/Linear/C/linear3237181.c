#include<stdio.h>


int main(){
   int a[16384], b[512], c, d, i, j, count;
   
   scanf("%d", &c);
   for (i = 0; i < c; i++){
      scanf("%d", &a[i]);
   }
   scanf("%d", &d);
   for(i = 0; i < d; i++){
      scanf("%d", &b[i]);
   }
   count = 0;
   for(i = 0; i < d; i++){
      for(j = 0; j < c; j++){
          if(b[i] == a[j]){
             count++;
             break;
          }
      }
   }
   printf("%d\n", count);
   
        
    
    return 0;
}

