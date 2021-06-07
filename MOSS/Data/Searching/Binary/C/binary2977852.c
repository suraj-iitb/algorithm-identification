// Binary search
#include <stdio.h>

int main() {
  int a[100000], b[50000];
  int left, mid, right;
  int i, n, q;
  int cnt = 0;

  // input the number
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // input the search number
  scanf("%d", &q);
  for(i = 0; i < q; i++) {
    scanf("%d", &b[i]);
  }

  // search
  for(i = 0; i < q; i++) {
    left = 0;
    right = n;
    while(left < right) {
      mid = (left + right) / 2;
      if(b[i] == a[mid]) {
	cnt++;
	break;
      }
      if(b[i] > a[mid]) {
	left = mid + 1;
      }
      else if(b[i] < a[mid]) {
	right = mid;
      }
    }
  }

  printf("%d\n", cnt);
  
  return 0;
}

