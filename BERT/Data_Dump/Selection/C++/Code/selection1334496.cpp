#include<stdio.h>
#define A 100;
 
main()
{
 
  int num[100], t = 0;
  int i,j;
  int max, mini, s;
 
  scanf("%d", &max);
 
 for(i = 0; i < max; i++){
 
    scanf("%d", &num[i]);
 
  }
 
 
 for(i = 0; i < max; i++){
    
   mini = i;
    
   for(j = i; j < max; j++){
      
     if(num[j] < num[mini]) mini = j;
      
   }
    
     if(mini != i){
       s = num[i];
       num[i] = num[mini];
       num[mini] = s;
       t++;
     }
 }
 for(i = 0; i < max; i++){
 
   if(i>0) printf(" ");
 
   printf("%d",num[i]);
 
 }
 
 printf("\n%d\n",t);
 
 return 0;
}
