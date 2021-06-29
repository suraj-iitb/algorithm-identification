#include <stdio.h>

#define MAX 100

int main() {
  int n, i, j, flag, tmp, cnt = 0;
  int array[MAX];

  scanf("%d\n", &n);
  i = 0;
  while ((scanf("%d", &array[i])) != EOF) {
    i++;
  }

  flag = 1;
  i = 0;
  while (flag) {
    flag = 0;
    for (j = n-1; j >= i+1; j--) {
      if (array[j] < array[j-1]) {
        tmp = array[j];
        array[j] = array[j-1];
        array[j-1] = tmp;
        flag = 1;
        cnt++;
      }
    }
    i++;
  }

  for (i = 0; i < n; i++) {
    if (i == n-1) {
      printf("%d\n", array[i]);
      break;
    }
    printf("%d ", array[i]);
  }
  printf("%d\n", cnt);

  return 0;
}
