#include <stdio.h>
int main () {
  int minj, a[100], n, i, j, num = 0, tmp;

  scanf("%d", &n);
  for(i = 0 ; i < n ; i++) {
    scanf("%d", &a[i]);
  }

  for(i = 0 ; i < n ; i++) {
    minj = i;
    for(j = i ; j < n ; j++) {
      if(a[j] < a[minj]) {
	minj = j;
      }
    }
     if(minj != i) {
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      num++;
     }
  }

  for(i = 0 ; i < n ; i++) {
    printf("%d", a[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n");
  printf("%d\n", num);

  return 0 ;
}
