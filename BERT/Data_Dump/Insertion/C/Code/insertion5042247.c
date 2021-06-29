#include <stdio.h>

int main(){
  int N, A[100];
  int i, j, key;

  scanf("%d",&N);

  for( i = 0; i < N; i++){
    scanf("%d ",&A[i]);
  }

  for(j = 0; j < N; j++){
  
    key = A[j];
    i = j - 1;
  
    while(i >= 0 && A[i] > key){
      A[i+1] = A[i];
      i--;
      A[i+1] = key;
    }

    for( i = 0; i < N; i++){
    printf("%d", A[i]);
    if (i >= 0 && i < N-1 ) printf(" ");
    }

    printf("\n");

  }
  
}
