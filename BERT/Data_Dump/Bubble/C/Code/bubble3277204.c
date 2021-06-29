#include <stdio.h>

int bubbleSort(int *,int);

int main(){

  int N,j;
  int A[100];
  int sw = 0;
 

  scanf("%d",&N);

  for(j=0;j < N;j++){
    scanf("%d",&A[j]);
  }

  sw = bubbleSort(A,N);
  
 for(j=0 ;j < N;j++){
   
   if(j > 0){
     printf(" ");
   }
   
   printf("%d",A[j]);
 }
 printf("\n");
 
 
 printf("%d\n",sw);
 
 return 0;
}


int bubbleSort(int A[],int N){
  int temp = 0;
  int flag,i,j;
  int sw = 0;
  
  
  flag = 1;
  i = 0;
  
  while(flag){
    
  flag = 0;

  for(i=0 ; i<N ; i++){
  
  for(j= N - 1;j >= i + 1;j--){
    
    if(A[j] < A[j-1]){
      
      temp = A[j];
      A[j] = A[j-1];
      A[j-1] = temp;
      
      flag = 1;
      sw++;
      
    }
  }
  
  }
  
  }
  
  return sw;
}


  

