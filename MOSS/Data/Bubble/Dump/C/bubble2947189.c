#include<stdio.h>
#define M 100

int count=0;

void bubbleSort(int *A,int N){

  int y,i,j,flag = 1;
  
  while(flag==1){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j] < A[j-1]){
	y = A[j];
	A[j] = A[j-1];
	A[j-1] = y;
	flag = 1;
	count++;
      }
    }
  }
    
  for(i=0;i<N;i++){
    if(i==N-1) printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");
  printf("%d\n",count);

}

int main(){
  
  int x,i,j,A[M],B[M];

  scanf("%d",&x);

  for(i=0;i<x;i++){
    scanf("%d",&A[i]);
  }

  bubbleSort(A,x);


  return 0;
}

  

