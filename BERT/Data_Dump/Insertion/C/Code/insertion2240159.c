#include <stdint.h>
#include <stdio.h>

#define MAX_DATA_NUM 100

void dump_array(int32_t num, int32_t *array)
{
  int i = 0;
  for (i = i; i < num; i++) {
    printf("%d", array[i]);
    if (i < (num - 1)) {
      printf(" ");
    }
  }

  printf("\n");
  return;
}

void insertion_sort(int32_t num, int32_t *data)
{
  int i;
  for (i = 0; i < num; i++) {
    int32_t v = data[i];
    int j = i - 1;
    while ((j >= 0) && data[j] > v) {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = v;
    dump_array(num, data);
  }

  return;
}

int main(void)
{
  int32_t num;
  int32_t data[MAX_DATA_NUM];

  scanf("%d", &num);
  int i;
  for (i = 0; i < num; i++) {
    scanf("%d ", &data[i]);
  }

  insertion_sort(num, data);

  return 0;
}
