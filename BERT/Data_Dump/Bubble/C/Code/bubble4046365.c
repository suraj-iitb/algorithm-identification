#include <stdio.h>
#define N 100
int main()

{
int kirito[N],kurain,asuna=0,i,j,sirika,rizu;

 scanf("%d",&kurain);
 for(i=0;i<kurain;i++)
     scanf("%d",&kirito[i]);

 
 
 for(i=0;i<kurain;i++){

   for(j=kurain-1;j>i;--j){
     if(kirito[j]<kirito[j-1]){
       sirika=kirito[j-1];
       kirito[j-1]=kirito[j];
       kirito[j]=sirika;
     
   asuna++;
     }
   }
 }


 for(i=0;i<kurain;i++){
   if(i>0)printf(" ");
   printf("%d",kirito[i]);
 }
 printf("\n");
 printf("%d\n",asuna);

 return 0;
}

