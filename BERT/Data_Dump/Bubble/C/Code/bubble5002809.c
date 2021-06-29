#include <stdio.h>
int main(){
  int n, a[100] = {0}, swap = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int j = 0; j < n; j++) {
    for (int k = 0; k < n-j-1; k++) {
      if (a[k] > a[k+1]) {
        int temp = a[k];
        a[k] = a[k+1];
        a[k+1] = temp;
        swap += 1;
      }
    }
  }

  for (int i = 0; i < n-1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1],swap);
  return 0;
}
