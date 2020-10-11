#include <stdio.h>

#define N 100


int main() {
  int data[N];
  int i, j, n, temp, count = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }
  for(i = 0; i < n; i++) {
    for (j = n-1; j >= i+1; j--) {
      if (data[j] < data[j-1]) {
	temp = data[j];
	data[j] = data[j-1];
	data[j-1] = temp;
	count++;
      }
    }
  }
  
  for (i = 0; i < n; i++) {
    printf("%d", data[i]);
    if (i == n-1) printf("\n");
    else printf(" ");
  }

  printf("%d\n", count);

  return 0;
}

