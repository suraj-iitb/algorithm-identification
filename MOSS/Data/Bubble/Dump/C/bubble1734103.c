#include <stdio.h>

int main(){
  int i, j, N, A[101], swap=0, n;

  scanf("%d", &N);
  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	n = A[j];
	A[j] = A[j-1];
	A[j-1] = n;
	swap++;
      }
    }
  }

  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", swap);

  return 0;
}
