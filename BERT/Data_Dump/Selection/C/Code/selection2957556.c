#include<stdio.h>

 int main(){

   int i, j, A[100], n, len, minj, c=0;
   scanf("%d", &len);
   for(i=0; i<len; i++){
     scanf("%d", &A[i]);
   }

   for(i=0; i<len; i++){
     minj = i;

     for(j=i; j<len; j++){

 if(A[j] < A[minj]){
 minj =  j;
 }
     }

     if(minj != i){
       n = A[i];
       A[i] = A[minj];
       A[minj] = n;

       c++;
     }
   }
   for(j=0; j < len; j++){

     printf("%d",A[j]);
     if(j != len-1)
     printf(" ");
   }
   printf("\n");
   printf("%d\n",c);

   return 0;
 }

