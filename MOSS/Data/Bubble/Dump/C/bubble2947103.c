// Bubble sort
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j;
  int n, tmp;
  int cnt = 0;
  int *a;

  // input the size of an array
  scanf("%d", &n);

  a = (int *)malloc(n * sizeof(int));

  // input the number of an array
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // sorting
  for(i = 0; i < n - 1; i++) {
    for(j = n - 1; j > i; j--) {
      if(a[j] < a[j - 1]) {
	tmp = a[j];
	a[j] = a[j - 1];
	a[j - 1] = tmp;
	cnt++;
      }
    }
  }

  // output
  for(i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i != n - 1) printf(" ");
    else printf("\n");
  }
  printf("%d\n", cnt);
  
  return 0;
}

