#include<stdio.h>
 
 int main(){
   int a[110],n,temp;
   int i,count=0; 
   int flag;

   scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%d",&a[i]);
   flag = 1;
   
   while(flag){
     flag = 0;
     for(i=n-1;i>0;i--){
       if(a[i]<a[i-1]){
	 temp = a[i];
	 a[i] = a[i-1];
	 a[i-1] = temp;
	 flag=1;
	 count++;
       }
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

