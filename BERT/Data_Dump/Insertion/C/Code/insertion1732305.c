#include <stdio.h>

int main() {

  int v, i, j, n, a[1000];
  
  scanf("%d", &n);
  for(i = 0;i < n; i++) scanf("%d", &a[i]);

  for(i = 1;i <= n;i++) {
    for(j = 0;j < n; j++) {
      printf("%d",a[j]);
      if(j + 1 != n) printf(" ");
    }
    printf("\n");
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }

  return 0;
}
