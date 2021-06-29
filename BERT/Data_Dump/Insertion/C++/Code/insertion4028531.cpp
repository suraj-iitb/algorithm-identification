#include<stdio.h>
 int main(){
   int a[100],N,i,j,k,key;
   scanf("%d",&N);
    for(i=1;i<N+1;i++){
     scanf("%d",&a[i]);
   }
   for(j=1;j<N+1;j++){
     key=a[j];
     i=j-1;
     while( i>0 && a[i]>key){
       a[i+1]=a[i];
       i--;
       a[i+1]=key;
     }
     for(k=1;k<N;k++){
	 printf("%d ",a[k]);
   }
     printf("%d",a[N]);
       printf("\n");
   }
     
     return 0;
 }
