#include <stdio.h>

int main() {

  int i,j,minj,N,A[100],temp,count=0; 

  scanf("%d",&N);
  for(i = 0; i < N; i++) {
    scanf("%d",&A[i]);
  }

  for(i = 0; i <= N-1; i++) {
    minj = i;
    for(j = i; j <= N-1; j++) {
      if(A[j] < A[minj]) {
	minj = j;
      }
    }
    if(minj != i) count++;
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;    
  }

  for(i = 0; i < N; i++) {
    if(i) printf(" ");
    printf("%d",A[i]);
   
  }
  printf("\n%d\n",count);
  
  return 0;
}

