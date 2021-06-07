#include <stdio.h>

#define SIZEN 100000
#define SIZEQ 50000

int binarySearch(int *S, int n, int key){
  int left = 0, right = n, mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (S[mid] == key)
      return 1;
    else if (key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  // not found
  return 0;
}

int main(void){
  int n, q, S[SIZEN] = {0}, T[SIZEQ] = {0}, C = 0, i;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++)
    scanf("%d", &T[i]);

  // search for S
  for (i = 0; i < q; i++)
    if (binarySearch(S, n, T[i]))
      C++;
  printf("%d\n", C);

  return 0;
}
