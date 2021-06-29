#include <stdio.h>
#define NOT_FOUND -1

int binarySearch(int *, int, int);

int main()
{
  int i, j, n, q;
  int count = 0;

  scanf("%d", &n);
  int S[n];
  for(i=0;i<n;i++) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  int T[q];
  for(i=0;i<q;i++) {
    scanf("%d", &T[i]);
  }

  for(i=0;i<q;i++) {
    if(binarySearch(S, n, T[i])!=NOT_FOUND)
      count ++;
  }
  printf("%d\n", count);

  return 0;
}

int binarySearch(int *A, int n, int key)
{
    int mid;
    int left = 0;
    int right = n;
    while (left < right) {
        mid = (left + right) / 2;
        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return NOT_FOUND;
}

