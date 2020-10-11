#include<stdio.h>

int main(){
   int i,j,x,A[100],N,count =0,flag = 1; // 逆の隣接要素が存在する
   
   scanf("%d",&N);
   
   for(i = 0 ; i < N ; i++){
       scanf("%d",&A[i]);
   }
   
   while(flag){
     flag = 0;
     for (j=N-1 ; j >= 1 ; j--){
       if(A[j] < A[j-1]){
           x = A[j];
           A[j] = A[j-1];
           A[j-1] = x;
         flag = 1;
         count++;
       }
     }
   }
    for(i = 0 ; i < N ; i++){
       printf("%d",A[i]);
       if(i+1!=N){
           printf(" ");
       }
   }
   printf("\n%d\n",count);
}
