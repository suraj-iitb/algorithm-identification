#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,j,flag,count=0,sub;
  int *A;

  scanf("%d",&n);
  A = (int *)malloc(sizeof(int) * n);
  if(A == NULL) exit(0);

  for(j = 0;j < n;j++){
    scanf("%d",&A[j]);
  }

  flag = 1;

  while(flag == 1){
    flag = 0;
    for(j = n-1;j >= 1;j--){
      if(A[j] < A[j-1]){
	sub = A[j-1];
	A[j-1] = A[j];
	A[j] = sub;
	flag = 1;
	count++;
      }
    }
  }

  for(j = 0;j < n;j++){
    printf("%d",A[j]);
    if(j != n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  free(A);

  return 0;
}
