#include <stdio.h>

int main(){
  int A[100];
  int i, j, N, flag = 1,count = 0;

  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  while(flag){
    flag = 0;
    for(j = N-1; j > 0; j--){
      if(A[j] < A[j-1]){
	i = A[j];
	A[j] = A[j-1];
	A[j-1] = i;
	flag = 1;
	count++;
      }
    }
  }

  for(i = 0; i < N-1; i++){
    printf("%d ",A[i]);
  }

  printf("%d\n%d\n",A[i],count);
  
  return 0;
}
