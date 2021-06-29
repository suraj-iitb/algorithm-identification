#include <stdio.h>
int main(){

   int n, i, j, v,  r[100]; 
   
   scanf("%d", &n);
   for(i = 0; i < n; i++){
       scanf("%d", &r[i]);
   }
   
   for(i = 1; i < n; i++){
   	   for(j = 0; j < n; j++){
   	   	    printf("%d", r[j]);
   	   	    if(j < n - 1){
   	   	    	printf(" ");
   	   	    }
   	   }
   	   printf("\n");
   	   v = r[i];
   	   j = i - 1;
   	   while(j >= 0 && r[j] > v){
   	   	    r[j + 1] = r[j];
   	   	    j--;
   	   	    r[j + 1] = v;
   	   }
   }
   
   for(i = 0; i < n; i++){
   	    printf("%d", r[i]);
   	    if(i < n - 1){
   	    	printf(" ");
   	    }
   }
   printf("\n");
   return 0;
}
