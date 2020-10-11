#include <stdio.h>
int main(){
  int i,j,N,flag,change;
  int A[100];
  scanf("%d",&N);
  for(i=0;i < N;i++){
    scanf("%d",&A[i]);
  }

 
  flag=0;
  for(i=0; i < N-1; i++){
    for( j=N-1; j > i ; j--){
      if(A[j] < A[j-1]){
	change = A[j];
	A[j]=A[j-1];
	A[j-1]=change;
	flag++;
      }
      
    }
  }

    for(j=0;j < N ;j++){
      if(j==N-1){
	printf("%d",A[j]);
      }
      else{
      printf("%d ",A[j]);
      }
    }
    printf("\n");
    printf("%d\n",flag);
      return 0;
  }
	  
  

