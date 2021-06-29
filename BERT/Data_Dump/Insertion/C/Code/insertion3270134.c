#include<stdio.h>
#include<stdlib.h>

int main(){
  int i, j, A[1000], N, v;
  scanf("%d", &N);
  if(!(N > 100)){
    for(i = 0; i < N; i++){
      scanf("%d", &A[i]);
      if(i != N-1)
	printf("%d ", A[i]);
      else
	printf("%d\n", A[i]);
    }
    for(i = 1; i < N; i++){
      v = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > v){
	A[j+1] = A[j];
	j--;
      }
      A[j+1] = v;

      for(j = 0; j < N; j++)
	if(j != N-1)
	  printf("%d ", A[j]);
	else
	  printf("%d\n", A[j]);
    }
  }
  return 0;
}

