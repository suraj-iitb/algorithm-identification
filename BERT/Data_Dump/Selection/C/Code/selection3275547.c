#include <stdio.h>

int main()
{
  
  int A[100], flag = 1, j, N, sort, i = 0, n = 0, minj;

  scanf("%d", &N);
  for(j = 0;j < N;j++){
    scanf("%d", &A[j]);
  }

  for(i = 0;i <= N - 1;i++){
    minj = i;
    for(j = i;j <= N - 1;j++){
      if(A[j] < A[minj])
	minj = j;      
    }
    if(A[i] != A[minj]) n++;
    sort = A[i];
    A[i] = A[minj];
    A[minj] = sort;
  }

  for(j = 0;j < N;j++){
    if(j) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n%d\n",n);

  return 0;
}
	

			      
    

