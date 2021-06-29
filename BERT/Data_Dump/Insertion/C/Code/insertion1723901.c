// Insertion_Sort.c

#include <stdio.h>

#define N 1000

int main() {

  int n, j, a[N], i, key = 0, k;

  scanf("%d", &n);
  
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n; i++) {

    key = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
      a[j + 1] = key;
    }

    for(k = 0; k < n; k++) {
      if(k < n - 1) {
	printf("%d ", a[k]);
      } else {
	printf("%d\n", a[k]);
      }
    }

  }

return 0;

}
