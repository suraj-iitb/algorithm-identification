#include<stdio.h>
 
 int main(){
   int a[110],n,temp;
   int i,j,count=0; 
   int minj;
   
   scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%d",&a[i]);

   for(i=0;i<n;i++){
     minj =i;
     for(j=i;j<n;j++){
       if(a[j]<a[minj]) minj = j;
     }
     if(minj != i){
       temp = a[i];
       a[i] = a[minj];
       a[minj] = temp;
       count++;
     }
   }
   
   for(i=0;i<n;i++){
     printf("%d",a[i]);
     if(i!=n-1) printf(" ");
     else printf("\n");
   }
   printf("%d\n",count);
   
   return 0;
 }

