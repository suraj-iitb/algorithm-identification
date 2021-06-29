#include <stdio.h>
int main () {
  int flag = 1, n, a[100], num = 0, i, j, tmp;

  scanf("%d", &n);
  for(i = 0 ; i < n ; i++) {
    scanf("%d", &a[i]);
  }

  while(flag) {
    flag = 0;
    for(j = n-1 ; j > 0 ; j--) {
      if(a[j] < a[j-1]) {
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	num++;
	flag = 1;
      }
    }
  }
  for(i = 0 ; i < n ; i++) {
    printf("%d", a[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n");
  printf("%d\n", num);

  return 0;
}
