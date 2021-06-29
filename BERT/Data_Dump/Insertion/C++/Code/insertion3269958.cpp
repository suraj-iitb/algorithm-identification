#include<stdio.h>
int main(){
  int a,B[1000],i,v,j,h;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&B[i]);
  }
 
   for (i=0;i<a;i++){
     v = B[i];
     j = i - 1;
     while (j >= 0 && B[j] > v){
       B[j+1] = B[j];
       j--;
       B[j+1] = v;
     }
     for(h=0;h<a;h++){
       if(h==a-1)printf("%d",B[h]);
       else printf("%d ",B[h]);
 }
     printf("\n");
}

   }


