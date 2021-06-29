#include<stdio.h>
int main(void){
 int a[100],n,i,j,v;
 scanf("%d",&n);
 for (i=1;i<n+1;i++){
   scanf("%d",&a[i]);
   if(i!=n) printf("%d ",a[i]);
   else printf("%d",a[i]);
 }
 printf("\n");  
 for (j=2;j<=n;j++){
   v=a[j];
   i=j-1;
   while ( i>0 && a[i]>v){
     a[i+1] = a[i];
     i--; 
   }
   a[i+1] = v;
   for ( i=1; i<n+1; i++){
     if(i!=n) printf("%d ",a[i]);
     else printf("%d",a[i]);
   }
   printf("\n");
 }
 return 0;
}
