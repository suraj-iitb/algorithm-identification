#include<stdio.h>
int main()
{
   int j,N,A[100],count,tmp;
   int flag;
   scanf("%d",&N);
for(j = 0; j < N; j++){
   scanf("%d",&A[j]);
}
flag = 1;
while(flag == 1){
    flag = 0;
       for(j = N-1; j >= 1; j--){
           if(A[j] < A[j-1]){
               tmp = A[j];
               A[j] = A[j-1];
               A[j-1] = tmp;
               count++;
               flag = 1;
           }
       }
   } 
   for(j = 0; j < N; j++){
   printf("%d",A[j]);
   if(j < N-1)
   printf(" ");
   }
   printf("\n");
   printf("%d\n",count);
   return 0;
}
