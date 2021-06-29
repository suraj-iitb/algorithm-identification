#include<stdio.h>
int main()
{
 int mothernum, mother[10000], kidsnum, kids[500]; 
 int i, j, kosuu=0;
 
 scanf("%d", &mothernum);
 for (i = 0; i < mothernum; i++) {
   scanf("%d", &mother[i]);
 }
  
 scanf("%d", &kidsnum);
 for(i = 0; i < kidsnum; i++) {
   scanf("%d", &kids[i]);
 }
 
 for (i = 0; i < kidsnum; i++){
   for (j = 0; j < mothernum; j++) {
     if (kids[i] == mother[j]) {
       kosuu++;
       break;
     }
   }
 }
 
 printf("%d\n",kosuu); 

 return 0;
}
