#include <stdio.h>

int BubbleSort(int n, int num[]) {
  int i, j;
  int cnt = 0;
  for (i = 1; i < n; i++) {
    for (j = i; 0 < j; j--) {
      if (num[j] < num[j-1]) {
	int tmp;
	tmp = num[j];
	num[j] = num[j-1];
	num[j-1] = tmp;
	cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  int n;
  int num[100];
  int i;
  int count;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &num[i]);
  }

  count = BubbleSort(n, num);

  for (i = 0; i < n; i++) {
    printf("%d", num[i]);
    if (i == n-1) break;
    putchar(' ');
  }
  putchar('\n');
  printf("%d\n", count);
  
  return 0;
}

