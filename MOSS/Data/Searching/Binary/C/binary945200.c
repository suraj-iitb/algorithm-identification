#include <stdio.h>

#define N 100000

int n, q;
int s[N], t[N];
int binary(int);

main() {
  int i, judge, count = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%d", &t[i]);
  }

  for(i = 0; i < q; i++) {
    judge = binary(t[i]);
    if(judge == 1) {
      count++;
    }
    else {
      continue;
    }
  }

  printf("%d\n", count);
  return 0;
}

int binary(int key) {
  int mid, left = 0, right = n;
  while(left < right) {
    mid = (left + right) / 2;
    if(key == s[mid]) {
      return 1;
    }
    if(key > s[mid]) {
      left = mid + 1;
    }
    else if(key < s[mid]) {
      right = mid;
    }
  }
  return 0;
}
