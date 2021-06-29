#include <stdio.h>
#include <stdlib.h>

int main(){
  int N;
  int A[100];
  int i,j;
  int count = 0;
  int temp;
  
  scanf("%d",&N);
  
  for(i = 0 ;i < N ;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N-1 ;i++){
    for(j = N-1; j > i; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
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

