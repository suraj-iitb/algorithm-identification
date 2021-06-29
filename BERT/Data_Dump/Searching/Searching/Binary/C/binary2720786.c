#include <stdio.h>

int n;
int S[100000];

int BinarySearch(int key) {
  int left = 0;
  int right = n;
  int mid;

  while (left < right) {
    mid = (left+right) / 2;
    if (S[mid] == key) {
      return 1;
    }
    else if (S[mid] < key) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }
  return 0;
}

int main() {
  int m, T[50000];
  int i;
  int count = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%d", &T[i]);
  }

  for (i = 0; i < m; i++) {
    if (BinarySearch(T[i])) {
      count++;
    }
  }

  printf("%d\n", count);
  

  return 0;
}

