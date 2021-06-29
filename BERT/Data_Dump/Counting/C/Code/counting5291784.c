#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void print_a(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d", arr[n]);
  printf("\n");
}


int max_arr(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}


void count_sort(int arr[], int n) {
  int output[n + 1];

  int max = max_arr(arr, n);

  int count[max + 1];

  for (int i = 0; i <= max; i++) {
    count[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    count[arr[i]] += 1;
  }

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n; i >= 1; i--) {
    output[count[arr[i]]] = arr[i];
    count[arr[i]]--;
  }

  for(int i = 1; i <= n; i++) {
    arr[i] = output[i];
  }

}


int main(void) {
  int n;
  scanf("%d", &n);

  int arr[n + 1];

  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }

  count_sort(arr, n);

  print_a(arr, n);

  return 0;
}

