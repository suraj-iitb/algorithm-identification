#include <stdio.h>

int main()
{
  int A[100], N, a, count=0, i, j, minj;

  scanf("%d",&N);
  for(j = 0 ; j < N ; j++){
    scanf("%d",&A[j]);
  }
  
  for(i = 0 ; i < N-1 ; i++){
    minj = i;
    for(j = i ; j <= N-1 ; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
    if(i != minj){
    count++;
    }
  }

  for(i = 0 ; i < N-1 ; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}
