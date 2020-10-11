#include<stdio.h>

#define MAX 100

int bubbleSort(int *,int);

int main(){

  int  N , j , flag , i , aa , temp , q ;
  
  int  A[MAX] ;
  
  scanf("%d",&N);
  for( i=0 ; i<N ; i++ )scanf("%d",&A[i]);
  


 
    for(i = 0;i<N-1;i++){
    for(j = N-1;j>=i + 1;j--){ 
    if(A[j] < A[j - 1]){
	temp=A[j-1];
	A[j-1]=A[j];
	A[j]=temp;
	q++;
      }
    }
    
  }
  
  

  for( j=0;j<N; j++){
  
    printf("%d",A[j]);
   

    if(j<N-1){
      printf(" ");
    }

  }
  printf("\n");
  printf("%d",q);
   printf("\n");
  return 0;
}





