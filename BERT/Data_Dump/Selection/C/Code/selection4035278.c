#include <stdio.h>

#define N 100
#define MAX 100

int main() {
  int data[N];
  int i, j, n, minj, count = 0, temp, flag = 0;;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }
  
  for (i = 0; i < n; i++) {
    minj = i;
    for (j = i; j < n; j++) {
      if (data[j] < data[minj]) {
	minj = j;
      }
    }
    if (i != minj) count++;
    temp = data[i];
    data[i] = data[minj];
    data[minj] = temp;
  }
  
  for (i = 0; i < n; i++) {
    printf("%d", data[i]);
    if (i == n-1) printf("\n");
    else printf(" ");
  }

  printf("%d\n", count);
  
  return 0;
}

