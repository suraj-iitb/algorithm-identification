#include<stdio.h>
int main(void){
 
     int N[100],n;
     int i,j,m;
     int k;
 
     scanf("%d",&n);
     for(i=0;i<n;i++){
         scanf("%d",&N[i]);
     }
 
     for(i=1;i<n;i++){
 
         for(j=0;j<n;j++){
             if(j!=0){
                 printf(" ");
             }
             printf("%d",N[j]);
         }
         printf("\n");
 
         m=i;
 
         for(j=i-1;j>=0;j--){
             if(N[j]<N[m]){
                 break;
             }
             else{
                 k=N[j];
                 N[j]=N[m];
                 N[m]=k;
                 m--;
             }
         }
 
     }
 
     for(j=0;j<n;j++){
             if(j!=0){
                 printf(" ");
             }
             printf("%d",N[j]);
         }
     printf("\n");
 
     return 0;
 }
