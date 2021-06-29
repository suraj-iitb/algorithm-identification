#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void print_a(int arr[], int n) {
  
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i != n - 1) {
      printf(" ");
    }
  }
  printf("\n");
}

int *insertion_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
    print_a(arr, n);
  }

  return arr;
}

int main(int argc, char *argv[]) {

  int count;
  scanf("%d", &count);

  int a[count];
  for (int i = 0; i < count; i++) {
    scanf("%d", &a[i]);
  }

  insertion_sort(a, count);

  return 0;
}

