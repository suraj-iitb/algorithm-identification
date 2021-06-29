#include <stdio.h>

int binarySearch(int *, int, int);


int main() {
  int i, j, n, q, count = 0, flag = 0;
  int datas[100000], dataq[50000];

  scanf("%d", &n);
  for (i= 0; i < n; i++) {
    scanf("%d", &datas[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &dataq[i]);
  }

  for (i = 0; i < q; i++) {
    flag = binarySearch(datas, n, dataq[i]);
    if (flag == 1) count++;
  }
  
  printf("%d\n", count);



  return 0;
}


int binarySearch(int *s, int n, int key) {
  int left, right, mid;
  left = 0;
  right = n;

  while (left < right) {
    mid = (left + right) / 2;
    if (s[mid] == key) return 1;

    else if (key < s[mid]) right = mid;

    else left = mid + 1;
  }

  return 0;
}

