#include <stdio.h>

int main() {

  int i,j,N,temp,A[100],count=0;
  scanf("%d",&N);
  for(i = 0; i < N; i++) {
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N; i++) {
    for(j = N-1; j >= i+1; j--) {
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
      }
    }
  }
  
    

  
  for(i = 0; i < N; i++) {
    if(i) printf(" ");
    printf("%d",A[i]);
   
  }
  printf("\n%d\n",count);

  return 0;
}

