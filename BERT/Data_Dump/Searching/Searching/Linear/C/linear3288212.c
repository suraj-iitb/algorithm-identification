#include <stdio.h>

 
 int main(){

   int i,j,m,n,cnt=0;
   long long a[10005],b[505];

   scanf("%d",&m);
   for(i=0;i<m;i++){
     scanf("%lld",&a[i]);
     //  printf("%d ",a[i]);
   }
   scanf("%d",&n);
   for(i=0;i<n;i++){
     scanf("%lld",&b[i]);
     //  printf("%d ",b[i]);
   }

   for(j=0;j<n;j++){
     i=0;
     a[m]=b[j];
     
     while(1){
       if(i==m-1){
	 break;
       }
       if(a[i]==a[m]){
	 cnt++;
	 break;
       }
       i++;
     }
     
   }

   printf("%d\n",cnt);

   
   
   return 0;
 }

