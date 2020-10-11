#include<stdio.h>

int main(void){
  int N,i,j,k,x;
  int A[100];
  
  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  x=0;
 for(i=0;i<N;i++){
   for(j=N-1; i<j; j--){
     k = A[j];
     if(A[j] < A[j-1]){
       A[j]=A[j-1];
       A[j-1]=k;
       x++;
     }
   }
 }
 
 for(i=0;i<N;i++){
   if(i != 0)
     {
       printf(" ");
     }
   printf("%d",A[i]);
 }
 printf("\n");
 printf("%d\n",x);
 return 0;
}
