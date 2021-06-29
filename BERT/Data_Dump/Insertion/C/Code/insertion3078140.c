#include <stdio.h>

int main()
{
  int h,i,j,d,K;

  scanf("%d",&h);

  int data[h];
  
  for(i=0; i<h; i++){
    scanf("%d",&data[i]);
  }

   for(i=1; i<h+1; i++){
     K= data[i];
     j = i-1;

     for(d=0; d<h-1; d++){
       printf("%d ",data[d]);
     }
     printf("%d",data[h-1]);
     printf("\n");

     while(j>=0 && data[j] >K){
       data[j+1]=data[j];
       j--;
       data[j+1]=K;
     }
   }
   return 0;
}
  

