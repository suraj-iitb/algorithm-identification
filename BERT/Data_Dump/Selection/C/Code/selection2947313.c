// Selection sort
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *a;
  int i, j, n, tmp;
  int cnt = 0;
  int min;

  // input the size of an array
  scanf("%d", &n);
  a = (int *)malloc(n * sizeof(int));

  // input the number of array
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // sorting
  for(i = 0; i < n; i++) {
    min = i;
    for(j = i; j < n; j++) {
      if(a[j] < a[min]) {
	min = j;
      }
    }
    // swap a[i] and a[min]
    if(a[i] > a[min]){
      cnt++;
      tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
    }
  }

  // output
  for(i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i != n-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n", cnt);
  return 0;
}

