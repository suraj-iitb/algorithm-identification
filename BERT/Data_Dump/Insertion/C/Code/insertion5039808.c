#include <stdio.h>

int main(){
  int N;
  scanf("%d",&N);
  int A[101];
  for(int i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(int k = 0; k < N; k++){
    printf("%d",A[k]);
    if(k != N-1){
      printf(" ");
    }
  }
  printf("\n");
  
  for(int i = 1; i < N; i++){
    int key = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(int k = 0; k < N; k++){
      printf("%d",A[k]);
      if(k != N-1){
	printf(" ");
      }
    }
    printf("\n");
  }

  
}

