#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_a(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d", arr[n - 1]);
  printf("\n");
}

int main() {
  int n;

  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int swaps = 0;

  for (int i = 0; i < n; i++) {
    int min = i;

    for (int j = i; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;
    if (min != i) swaps += 1;

  }
  print_a(arr, n);
  printf("%d\n", swaps);

  return 0;
}

