#include <stdio.h>
int main(){
    int n, a[100] = {0};

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int l = 1; l < n; l++) {
      int j = l;
      for (int k = 0; k < n-1; k++)
      {
        printf("%d ", a[k]);
      }
      printf("%d\n", a[n-1]);
      while (j > 0 && a[j] < a[j-1]) {
          int temp = a[j];
          a[j] = a[j-1];
          a[j-1] = temp;
          j -= 1;
      }
  }

  for (int k = 0; k < n-1; k++)
      {
        printf("%d ", a[k]);
      }
  printf("%d\n", a[n-1]);
}
