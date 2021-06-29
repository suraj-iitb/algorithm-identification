#include<stdio.h>

int main(){

  int A[10000],B[500],N,M,i,j,key,count=0;

  for(i=0 ; i<10000 ;i++){
    A[i] = 0;    
  }

  for(i=0 ; i<500 ;i++){
    B[i] = 0;    
  }

  scanf("%d",&N);
  
  for(i=0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }  

  scanf("%d",&M);
  
  for(i=0 ; i<M ; i++){
    scanf("%d",&B[i]);
  }  
  for(i=0 ; i<M ; i++){
    A[N] = B[i];    
   
    for(j=0 ; j<=N ; j++){
       if(A[j] == A[N]) break;
     }    
    if(j != N) count++;
   
    }
    printf("%d\n",count);
    return 0;
  }

