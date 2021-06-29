#include<stdio.h>
static const int LENGTH_MAX = 100;

void print_array(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d", array[i]);

    if (i != size -1) {
      printf(" ");
    }
  }

  printf("\n");
}

void swap(int* val1, int* val2) {
  int tmp = *val1;
  *val1 = *val2;
  *val2 = tmp;
}

int main() {
  int array[LENGTH_MAX];
  int size;

  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }

  print_array(array, size);
  for(int i = 1; i < size; i++) {
    for(int j = i; j > 0; j--) {
      if (array[j - 1] <= array[j]) {
        break;
      }

      swap(&array[j -1], &array[j]);
    }

    print_array(array, size);
  }
}

