#include <stdio.h>

int main(){
  int N;
  
  scanf("%d",&N);
  if(1 > N || N > 100) return 0;

  int A[N+1],i,j;
  int v;

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i != N - 1)printf(" ");
    else printf("\n");
  }
  
  for(i = 1; i < N; i++){
    v = A[i];
    j = i - 1;
    
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(j = 0; j < N; j++){
      printf("%d",A[j]);
      
      if(j != N - 1){
	printf(" ");
      }
      else printf("\n");
    }
  }
  return 0;
}
