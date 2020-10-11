#include <stdio.h>

int main()
{
  int N, i, j, flag=1, work, count=0, minj, A[100];

  scanf("%d", &N);
  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }

  for(i=0; i<N; i++){
    minj=i;
    for(j=i; j<N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(minj != i){
      work=A[i];
      A[i]=A[minj];
      A[minj] =work;
      count++;
    }
  }

  for(i=0;i<N;i++){
    if(i==N-1){
      printf("%d",A[i]);
      break;
    }
    printf("%d ", A[i]);
  }

  printf("\n%d\n", count);
  
  return 0;
}
