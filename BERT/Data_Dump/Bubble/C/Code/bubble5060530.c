#include<stdio.h>
#include<stdlib.h>//BubbleSort//

#define Max 1000000

int BubbleSort(int *,int);

int main(){

  int  N , J , Flag , i , TEMP , Q ;
  
  int  A[Max] ;
  
  scanf("%d",&N);
  for( i=0 ; i<N ; i++ )scanf("%d",&A[i]);
  


 
  for(i = 0;i<N-1;i++){//一番小さい値を左に//
    for(J = N-1;J>=i + 1;J--){ 
    if(A[J] < A[J - 1]){
      TEMP=A[J-1];
      A[J-1]=A[J];
	A[J]=TEMP;
	Q++;//一度移動するごとにカウント//
      }
    }
    
  }
  
  

  for( J=0;J<N; J++){
  
    printf("%d",A[J]);
   

    if(J<N-1){
      printf(" ");
    }

  }
  printf("\n");
  printf("%d",Q);
   printf("\n");
  return 0;
}
