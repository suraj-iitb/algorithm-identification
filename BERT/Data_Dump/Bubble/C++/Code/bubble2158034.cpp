//Insertion_Sort.cpp
#include<iostream>
#include<cstdio>

int bubbleSort(int A[], int N){
  int sw = 0;
  for (size_t i = 0; i <= N; i++) {
    for (size_t j = N-1; j > i; j--) {
      if (A[j-1] > A[j]) {
        int v = A[j];
        A[j] = A[j-1];
        A[j-1] = v;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
  int n; // a number of scores
  scanf("%d", &n);

  int arr[100];
  
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int ans = bubbleSort(arr, n);
  for (size_t k = 0; k < n; k++) {
      printf("%d%c",arr[k],(k==n-1)? '\n':' ');
  }
  printf("%d\n", ans);
  return 0;
}
