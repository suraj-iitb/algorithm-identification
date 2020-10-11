#include<stdio.h>
#include<stdlib.h>
 int main(){
   int b,i,j,N,v;
   scanf("%d",&N);
   int A[N];
   if(N<0&&100<N)exit(1);
  
   for(b=0;b<N;b++){
     scanf("%d",&A[b]);
   }
   printf("%d",A[0]);
   for(b=1;b<N;b++)printf(" %d",A[b]);
   printf("\n");
   for(i=1;i<=N-1;i++){
     v=A[i];
     j=i-1;
     while(j>=0&&A[j]>v){
       A[j+1]=A[j];
       j--;
       A[j+1]=v;
     }
     printf("%d",A[0]);
     for(b=1;b<N;b++)printf(" %d",A[b]);
     printf("\n");
   }
   return 0;
 }

