#include <stdio.h>

#define MAX 1000

int main() {
  int i,j,k,v;
  int N;
  int A[MAX];

  scanf("%d",&N);
  if(N < 0 || 100 < N){
    return 0;
  }
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < N; i++){
    v = A[i];
    j = i-1;

    while(j>=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      //printf("%d ",A[j]);                                                     
    }
    A[j+1] = v;
    for(k = 0; k < N; k++){
      if(k){
	printf(" ");
      }
      printf("%d",A[k]);
    }
    printf("\n");
  }
  //printf("\n");                                                               
  for(i = 0; i < N; i++){
    //printf("%d ",A[i]);                                                       
  }
  //printf("\n");                                                               

  return 0;
}
