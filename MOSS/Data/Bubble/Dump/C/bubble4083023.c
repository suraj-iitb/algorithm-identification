#include <stdio.h>

int bubbleSort(int *arr, int size) {
  int flg=1, tmp, cnt=0;
  while (flg) {
    flg=0;
    for (int i=size-1; i>0; i--) {
      if (arr[i]<arr[i-1]) {
        tmp=arr[i-1];
        arr[i-1]=arr[i];
        arr[i]=tmp;
        flg=1;
        cnt++;
      }
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

  int cnt=bubbleSort(arr, n);

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
