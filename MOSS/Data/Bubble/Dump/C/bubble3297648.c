#include <stdio.h>
#include <stdlib.h>

int main(){
  int flag=1, i=0, j, tmp, N, A[100],count=0;

  scanf("%d",&N);
  if(N<1 || N>100) exit(1);
  for(i=0; i<N; i++) {
    scanf("%d",&A[i]);
    if(A[i] > 100 || A[i] < 0) exit(2);
  }

  i=0;
  while(flag){
    flag = 0;
    for(j=N-1; j>=i+1; j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flag = 1;
	count++;
      }
    }
    i++;
  }

  for(j=0; j<N-1; j++) printf("%d ",A[j]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count);

  return 0;
}

