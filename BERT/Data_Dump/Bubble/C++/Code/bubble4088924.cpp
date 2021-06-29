#include <stdio.h>
void bubbleSort(int *arr, int arrsize, int *count) {
  int tmp,flag = 1;
  while (flag) {
    flag = 0;
    for (int i = arrsize - 1; i > 0; i--) {
      if (arr[i] < arr[i-1]) {
        tmp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = tmp;
        *count += 1;
        flag = 1;
      }
    }
  }
}
int main() {
  int n,count = 0;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  bubbleSort(arr,n,&count);
  for (int i = 0; i < n; i++) {
    if (i == n-1) printf("%d", arr[i]);
    else  printf("%d ", arr[i]);
  }
  printf("\n%d\n", count);
  return 0;
}

