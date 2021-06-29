#include <stdio.h>
int main(){

   int n, i, flag = 1, v, cnt = 0, r[100]; 
   
   scanf("%d", &n);
   for(i = 0; i < n; i++){
       scanf("%d", &r[i]);
   }
   
   while(flag) {
   	    flag = 0;
   	    for(i = n-1; i >= 1; i--){
   	   	   if(r[i] < r[i-1]){
   	   	       v = r[i];
   	   	       r[i] = r[i - 1];
   	   	       r[i - 1] = v;
   	   	       cnt++;
   	   	       flag = 1;
   	   	   }
   	   }
   }
   
   for(i = 0; i < n; i++){
   	    printf("%d", r[i]);
   	    if(i < n - 1)
   	    	printf(" ");
   	    else
   	        printf("\n");
   }
   printf("%d\n", cnt);
   	    
   return 0;
}
