#include <stdio.h>

int selectionSort(int *arr, int size) {
  int cnt=0;
  for (int i=0; i<size; i++) {
    int minj=i, tmp;
    for (int j=i+1; j<size; j++) {
      if (arr[minj]>arr[j]) {
        minj=j;
      }
    }
    if (minj!=i) {
      tmp=arr[i];
      arr[i]=arr[minj];
      arr[minj]=tmp;
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];

  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  int cnt = selectionSort(arr, n);

  for (int i=0; i<n; i++) {
    if (i<n-1) {
      printf("%d ", arr[i]);
    } else {
      printf("%d\n", arr[i]);
    }
  }

  printf("%d\n", cnt);
  return 0;
}
