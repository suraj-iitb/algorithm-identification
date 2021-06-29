#include<stdio.h>

int main(){
  int i, j, minj, temp, count, N, A[100];
  scanf("%d", &N);
  if(N >= 1 && N <= 100){
    for(i = 0; i < N; i++)
      scanf("%d", &A[i]);
    
    for(i = 0; i < N; i++){
      minj = i;
      for(j = i; j < N; j++){
	if (A[j] < A[minj])
	  minj = j;
      }
      if(i != minj){
	temp = A[i];
	A[i] = A[minj];
	A[minj] = temp;
	count++;
      }
    }
    for(i = 0; i < N; i++){
      if(i != N-1) printf("%d ",A[i]);
      else printf("%d\n", A[i]);
    }
    printf("%d\n", count);
  }
  return 0;
}

