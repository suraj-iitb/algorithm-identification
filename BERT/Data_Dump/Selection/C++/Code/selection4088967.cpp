#include <stdio.h>
void selectionSort(int *arr, int arrsize, int *count) {
  int minj, tmp;
  for (int i = 0; i < arrsize; i++) {
    minj = i;
    for (int j = i; j < arrsize; j++) {
      if (arr[j] < arr[minj]) minj = j;
    }
    if (i != minj) {
      tmp = arr[i];
      arr[i] = arr[minj];
      arr[minj] = tmp;
      *count += 1;
    }
  }
}
int main() {
  int num,count = 0;
  scanf("%d",&num);
  int arr[num];
  for (int i = 0; i < num; i++) scanf("%d", &arr[i]);
  selectionSort(arr,num,&count);
  for (int i = 0; i < num; i++) {
    if (i == num-1) printf("%d", arr[i]);
    else printf("%d ", arr[i]);
  }
  printf("\n%d\n", count);
  return 0;
}

