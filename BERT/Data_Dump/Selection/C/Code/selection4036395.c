#include <stdio.h>
#include <stdlib.h>

int main(){
  int N;
  int A[100];
  int B[100];
  int i,j,k,l,s,min;
  int count = 0;
  int temp;
  
  scanf("%d",&N);
  
  for(i = 0 ;i < N;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N-1; i++){
    
    for(k = 0; k < N-1; k++){
      if(A[k] < A[k+1]){
	l = 1;
      }
      else{
	l = 0;
	break;
      }
    }
    
    if(l == 1){
      break;
    }
    
    min = i;
    
    for(j = i; j < N; j++){
      if(A[j] < A[min]){//A[j]がA[min]を下回ればminをjにかえて新たな最小値とする
	min = j;
      }
    }
    for(j = 0; j < N; j++){
      B[j] = A[j];
    }
    
    temp = A[i];
    A[i] = A[min];
    A[min] = temp;
    
    for(j = 0; j < N; j++){
      if(B[j] == A[j]);
      else{
	count++;
	break;
      }
    }
  }
  
  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i == N-1){
      printf("\n");
      break;
    }
    else printf(" ");
  }
  
  printf("%d\n",count);
  
  return 0;
}

