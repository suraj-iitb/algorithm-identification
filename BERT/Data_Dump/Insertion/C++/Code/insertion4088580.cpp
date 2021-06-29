#include <stdio.h>
void printIntArr(int *arr, int arrsize) {
  for (int i = 0; i < arrsize; i++) {
    if (i==arrsize-1) printf("%d", arr[i]);
    else printf("%d ", arr[i]);
  }
  printf("\n");
}
void insertionSort(int *arr,int arrsize) {
  int tmp,j;
  for (int i = 1; i < arrsize; i++) {
    tmp = arr[i];
    j = i-1;
    while (j >= 0 && arr[j] > tmp) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = tmp;
    printIntArr(arr,arrsize);
  }
}
int main() {
  int arrsize;
  scanf("%d", &arrsize);
  int arr[arrsize];
  for (int i = 0; i < arrsize; i++) scanf("%d", &arr[i]);
  printIntArr(arr,arrsize);
  insertionSort(arr,arrsize);
  return 0;
}

