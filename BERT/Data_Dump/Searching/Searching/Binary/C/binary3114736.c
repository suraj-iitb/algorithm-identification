#include <stdio.h>

#define N_MAX 100000
#define Q_MAX 50000

int binarySearch(int key);

int S[N_MAX];
int T[Q_MAX];
int n, q;

int main(void) {
  int C = 0;
  int i, j;

  scanf("%d", &n);
  for(i=0; i<n; ++i) {
    scanf("%d", &S[i]);
  }

  scanf("%d", &q);
  for(i=0; i<q; ++i) {
    scanf("%d", &T[i]);
  }

  for(i=0; i<q; ++i) {
    C += binarySearch(T[i]);
  }

  printf("%d\n", C);

  return 0;
}

int binarySearch(int key) {
  int mid;
  int left = 0;
  int right = n;

  while(left < right) {
    mid = (left + right) / 2;

    if(S[mid] == key) {
      return 1;
    }
    else if(key < S[mid]) {
      right = mid;
    }
    else {
      left = mid + 1;
    }
  }

  return 0;
}

