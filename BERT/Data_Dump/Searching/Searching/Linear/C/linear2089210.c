#include <stdio.h>
  
int main(){
   int c, i, j, k, n, q;
   c=0;
   scanf("%d",&n);
   int a[10000];
   for(i=0;i < n;i++){
       scanf("%d",&a[i]);
   }
   scanf("%d",&q);
   int b[10000];
   for(i=0;i < q;i++){
       scanf("%d",&b[i]);
   }
   for(i=0;i < q;i++){
      for(j=0;j < n;j++){
         if(b[i] == a[j]){
               c++;
               break;
         }
      }
   }
   printf("%d\n",c);
   return 0;
}
