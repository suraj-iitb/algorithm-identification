#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


void print_a(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d", arr[n - 1]);
  printf("\n");
}


void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
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
    bool swapped = false;
    
    for (int j = 0; j < n - 1; j++) {
      
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swaps += 1;
        swapped = true;
      }
    }
    
    if (swapped == false) break;
  }

  print_a(arr, n);
  printf("%d\n", swaps);

  return 0;
}

