#include <stdio.h>

#define N 100

void swap(int *, int *);

int main()
{
  int i, j, count = 0, n, flag = 1, A[N], tmp = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);

  /*ここからが挿入ソート*/
  while(flag == 1){
    flag = 0;
    for(j = n - 1; j >= 1; j--){
      if(A[j] < A[j - 1]){
	swap(&A[j], &A[j - 1]);
	  flag = 1;
	count++;
      }
    }
  }
  for(i = 0; i < n; i++){
    if(i != 0)
  printf(" ");
  printf("%d", A[i]);
  }
  printf("\n%d\n", count);
  
  return 0;
}

void swap(int *x, int *y)
{
  int tmp = 0;
  tmp = *y;
  *y = *x;
  *x = tmp;
}



