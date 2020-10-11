#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
  int count;
  scanf("%d", &count);
  int numbers[count - 1], sortCounts = 0;

  for (int i = 0; i < count; ++i)
  {
    scanf("%d", &numbers[i]);
  }

  int swaped = 1, swapCount;

  while (swaped == 1)
  {
    swaped = 0;
    for (int j = 1; j < count; ++j)
    {
      if (numbers[j - 1] > numbers[j])
      {
        swapCount++;
        swap(&numbers[j - 1], &numbers[j]);
        swaped = 1;
      }
    }
  }

  for (int l = 0; l < count; ++l)
  {
    if (l == count - 1)
    {
      printf("%d", numbers[l]);
    }
    else
      printf("%d ", numbers[l]);
  }
  printf("\n%d\n", swapCount);

  return 0;
}
