#include <stdio.h>

#define N 100000

int binarySearch(int A[], int aLength, int key) {
  int left = 0;
  int right = aLength;
  int mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (A[mid] == key) return 1;
    if (A[mid] < key) {
      left = mid + 1;
    }
    else if (A[mid] > key) {
      right = mid;
    }
  }
  return 0;
}

int main() {
  int i, length, tLength;
  int count = 0;
  int S[N], T[N];
  scanf("%d", &length);
  for (i = 0; i < length; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &tLength);
  for (i = 0; i < tLength; i++) {
    scanf("%d", &T[i]);
    if (binarySearch(S, length, T[i]) == 1) {
      count++;
    }
}
  printf("%d\n", count);
return 0;
}
