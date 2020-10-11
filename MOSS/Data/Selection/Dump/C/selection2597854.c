#include <stdio.h>

int main(void)
{
  int a[100];
  int i, j, N, minj, num, temp;

  scanf("%d", &N);

  for(i = 0; i < N; i++)
    scanf("%d", &a[i]);

  for(i = 0; i < N-1; i++) {
    minj = i;
    for(j = i; j < N; j++) {
      if(a[j] < a[minj])
        minj = j;
    }
    temp = a[i];
    a[i] = a[minj];
    a[minj] = temp;
    if(i != minj)
      num++;
  }

  for(i = 0; i < N; i++) {
   printf("%d", a[i]);
   if(i != N-1)
     printf(" ");
  }
  printf("\n");
  printf("%d\n", num);

  return 0;
}
