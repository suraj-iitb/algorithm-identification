#include<iostream>
#include<cstdio>

int main() {
  int n; // a number of scores
  scanf("%d", &n);

  int arr[100];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    printf("%d%c",arr[i],(i==n-1)? '\n':' ');
  }

  for (size_t i = 1; i < n; i++) {
    int j = i - 1;
    int v = arr[i];
    while (arr[j] > v && j > -1) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = v;
    for (size_t k = 0; k < n; k++) {
      printf("%d%c",arr[k],(k==n-1)? '\n':' ');
    }

  }
  return 0;
}
