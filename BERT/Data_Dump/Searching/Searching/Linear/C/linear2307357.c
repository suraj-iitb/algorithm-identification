#include <stdio.h>

#define N 10000

int linearSearch(int A[], int aLength, int key) {
  int i;
  for (i = 0; i < aLength; i++) {
    if(A[i] == key) return 1;
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
    if (linearSearch(S, length, T[i]) == 1) {
      count++;
    }
}
  printf("%d\n", count);
return 0;
}
