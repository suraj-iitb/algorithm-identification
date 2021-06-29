#include <stdio.h>
 
#define MAX 100
 
int main() {
  int n, i, j, minj, cnt = 0;
  int array[MAX], tmp, flag;
 
  scanf("%d\n", &n);
  i = 0;
  while ((scanf("%d", &array[i])) != EOF) {
    i++;
  }

  for (i = 0; i < n; i++) {
    minj = i;
    flag = 0;
    for (j = i; j < n; j++) {
      if (array[j] < array[minj]) {
	minj = j;
	flag = 1;
      }
    }
    if (flag) {
      tmp = array[i];
      array[i] = array[minj];
      array[minj] = tmp;
      cnt++;
    }
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
