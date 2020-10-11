#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_num(int *array, int N);

int main() {
  int N, num;
  int i;
  int *array;

  scanf("%d", &N);

  array = (int *) calloc(N, sizeof(int));
  if (!array) {
    abort();
  }

  for (i=0; i<N; i++) {
    scanf("%d", &array[i]);
  }

  int j;
  int index;
  for (i=0; i<N; i++) {
    index = -1;
    for (j=i-1; j>=0; j--) {
      if (array[j] > array[i]) {
        index = j;
      }
      else {
        break;
      }
    }
    if (index != -1) {
      int tmp = array[i];
      memmove(&array[index+1], &array[index], sizeof(int)*(i-index));
      array[index]  = tmp;
    }
    print_num(array, N);
  }

  return 0;
}

void print_num(int *array, int N) {
  int i;
  for (i=0; i<N; i++) {
    printf("%d", array[i]);
    if (i + 1 != N) {
      putchar(' ');
    }
  }
  putchar('\n');
}
