#include <stdio.h>

int main()
{
  int A[100], flag = 1, j, N, sort, i = 0, n = 0;

  scanf("%d", &N);
  for(j = 0;j < N;j++){
     scanf("%d", &A[j]);
  }
  
  while(flag){
    flag = 0;
    for(j = N - 1;j >= i + 1;j--){
      if(A[j] < A[j-1]){
	sort = A[j];
	A[j] = A[j-1];
	A[j-1] = sort;
	n++;
        flag = 1;
      }
    }
      	i++;
  }
  for(j = 0;j < N;j++){
    if(j) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n%d\n",n);

  return 0;
}
	

