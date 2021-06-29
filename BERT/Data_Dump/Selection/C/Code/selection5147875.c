#include<stdio.h>

int main()
{
  int num;

  scanf("%d", &num);

  int i, j, minj, x, y, cnt = 0, A[num];

  for(i = 0; i < num; i++)scanf("%d", &A[i]);

  for(i = 0; i < num; i++){
    minj = i;
    for(j = i + 1; j < num; j++)
      {
        if(A[j] < A[minj])minj = j;
      }
    if(minj != i){
      y = A[minj];
      A[minj] = A[i];
      A[i] = y;
      cnt += 1;
    }
  }

  for(i = 0; i < num - 1; i++)printf("%d ", A[i]);
  printf("%d\n%d\n", A[num - 1], cnt);
  return 0;
}


