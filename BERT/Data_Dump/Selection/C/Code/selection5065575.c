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

void selectionSort(int A[],int N){ //選択ソート関数

  int tmp,k=0,i,minj;

  for(i=0;i<=N-1;i++){

    minj=i;
      for(int j=i;j<=N-1;j++){

	if(A[j]<A[minj]){

	  minj=j;
	  
	}}
	  tmp=A[i];    //配列の交換
	  A[i]=A[minj];
	  A[minj]=tmp;
	  if(i!=minj)
	    k++;
      

	
      
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

 

  selectionSort(A,N); //バブルソート

  return 0;
}

