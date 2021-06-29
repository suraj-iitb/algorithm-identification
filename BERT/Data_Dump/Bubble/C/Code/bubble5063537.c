#include <stdio.h>
#include <stdlib.h>

void printarray(int A[],int N,int k){

  int i;
  
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);  //出力
  }
  printf("%d",A[N-1]);
  printf("\n");
  
  printf("%d\n",k);
}

void bubblesort(int A[],int N){ //バブルソート関数

  int tmp,k=0,i;

  for(i=0;i<N-1;i++){
      
      for(int j=N-1;j>i;j--){

	if(A[j]<A[j-1]){

	  tmp=A[j];    //配列の交換
	  A[j]=A[j-1];
	  A[j-1]=tmp;
	 
	  ++k;
	 
	}
      }
      }
   
    
    printarray(A,N,k);
  }
  
int main(){


  int N,A[100],i,j;
  
  scanf("%d",&N); //入力

  if(1>N || N>100) exit(1); //制約
  
  for(i=0;i<N;i++){

    scanf("%d",&A[i]);

    if(A[i]<0 || A[i]>100) exit(2); //制約
  }

 

  bubblesort(A,N); //バブルソート

  return 0;
}

