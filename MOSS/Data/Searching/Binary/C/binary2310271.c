#include <stdio.h>
#define NOT_FOUND -1
int A[100000];
int main() {
  int i, j, n, m, l, count=0;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &m);
  int B[50000];
  for(i = 0; i < m; i++) {
    scanf("%d", &B[i]);
    l = binarySearch(n, B[i]);
    if(l != NOT_FOUND) count++;
  }
  printf("%d\n", count);
  return 0;
}

int binarySearch(int n, int key) {
  int mid, left=0, right=n;
  while(left < right) {
    mid = (left + right)/2;
    if(A[mid] == key) return mid;
    else if(key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return NOT_FOUND;
}
