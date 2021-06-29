#include<stdio.h>

int main()
{
  int num;

  scanf("%d", &num);

  int i, j, x = 0, y, A[num];

  for(i = 0; i < num; i++)scanf("%d", &A[i]);

  for(i = 0; i < num; i++){
    for(j = num - 1; j > i; j--){
      if(A[j] < A[j - 1]){
        y = A[j - 1];
        A[j - 1] = A[j];
        A[j] = y;
        x += 1;
      }
    }
  }
  for(i = 0; i < num - 1; i++)printf("%d ", A[i]);
  printf("%d\n%d\n", A[num - 1], x);
  return 0;
}

