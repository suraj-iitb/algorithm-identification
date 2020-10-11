#include <stdio.h>

int main() {
  int a[100];
  int n, temp, count = 0;
  int i, j, minj;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for(i = 0; i < n - 1; i++) {
    minj = i;
    for(j = i; j < n; j++) {
      if(a[j] < a[minj]) {
	minj = j;
      }
    }
    if(a[i] > a[minj]) {
      temp = a[i];
      a[i] = a[minj];
      a[minj] = temp;
      count++;
    }
  }

  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n - 1) printf(" ");
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
  
}
