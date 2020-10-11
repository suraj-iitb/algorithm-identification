#include <stdio.h>
#include <stdlib.h>

int main(){
  int b;
  int i,j,num,v;

  scanf("%d",&num);
  int a[num];
 for(i=0; i<num; i++){
   scanf("%d",&a[i]);
 }

 for(i=0; i<num; i++){

   v = a[i];
   b = i - 1;

   while(b>=0 && a[b] > v){
     a[b+1] = a[b];
     b--;
     a[b+1] =v;
   }
   for(j=0; j<num; j++){
     if(j!=num-1)printf("%d ",a[j]);
     else{
       printf("%d",a[j]);
     }
   }
 printf("\n");
}
return 0;
}

