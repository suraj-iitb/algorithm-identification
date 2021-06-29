#include <stdio.h>

int main(void)
{
  int a[100];
  int i, j, k, l, N, temp;
  int num = 0;

  scanf("%d", &N);

  for(i = 0; i < N; i++)
   scanf("%d", &a[i]);


  for(j = 0; j < N; j++) {
  for(i = N-1; i > j; i--) {
    if(a[i] < a[i-1]) {
      temp = a[i];
      a[i] = a[i-1];
      a[i-1] = temp;
      num++;
    }
  }
  }

  for(i = 0; i < N; i++) {
   printf("%d", a[i]);
   if(i != N-1)
   printf(" ");
  }
  printf("\n");

  printf("%d\n", num);
} 
