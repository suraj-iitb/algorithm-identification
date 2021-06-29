#include <stdio.h>
int main(){
  int i,N,j,A[100],tmp,count=0;
  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(j = 0; j < N-1; j++){
    for(i = N-1; i >= 1+j; i--){
      if(A[i] < A[i-1]){
	tmp = A[i];
	A[i] = A[i-1];
	A[i-1] = tmp;
	count++;
      }
    }
  }
  for(i = 0; i < N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}
