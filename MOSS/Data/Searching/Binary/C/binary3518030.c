#include <stdio.h>
#define MAX 100001
#define NOT_FOUND -1

int binarySearch(int *A, int N, int key) {
  int left = 0, right = N, mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(A[mid] == key) return mid;
    else if (key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return NOT_FOUND;
}

int main() {
  int n, q, s[MAX], t, i, count = 0;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  
  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%d", &t);
    if(binarySearch(s, n, t) >= 0) count++;
  }
  
  printf("%d\n", count);
  return 0;
}

