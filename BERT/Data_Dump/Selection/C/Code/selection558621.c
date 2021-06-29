#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(void) 
{
  int i, j, N, min, *sequence, operation = 0;

  scanf("%d", &N);

  sequence = (int *) malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) 
    scanf(" %d", &sequence[i]);

  for (i = 0; i < N; i++) {

    min = i;

    for (j = i; j < N; j++) 
      if (sequence[j] < sequence[min]) 
	min = j;

    if (min != i) {
      swap(&sequence[i], &sequence[min]);
      operation++;
    }
  }

  for (i = 0; i < N - 1; i++) 
    printf("%d ", sequence[i]);

  printf("%d\n", sequence[N - 1]);
  printf("%d\n", operation);

  return 0;
}

void 
swap(int *x, int *y) {

  int tmp;

  tmp = *x;
  *x  = *y;
  *y  = tmp;
}
