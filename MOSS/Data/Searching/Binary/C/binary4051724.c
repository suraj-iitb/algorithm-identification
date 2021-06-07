#include <stdio.h>

#define N 100000
#define NIL -1

int BinarySearch(int *, int, int);

int main() {

  int s[N];
  int t[N];
  int n, q;
  int cnt = 0;
  int i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t[i]);
  }

  for (i = 0; i < q; i++) {
    if(BinarySearch(s, n, t[i]) != NIL) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  
  return 0;
}


int BinarySearch(int s[], int n, int k) {
  int i;
  int left, right, mid;

  left = 0;
  right = n;
  
  while(left < right) {
    mid = (left + right)/2;

    if (s[mid] == k) {
      return mid;
    }
    else if (s[mid] < k) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }
  return NIL;
}

