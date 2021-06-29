#include <stdio.h>

int main(){
  int a[100], n,swap=0;

  scanf("%d", &n);
  for (int k = 0; k < n; k++) {
    scanf("%d", &a[k]);
  }

  for (int i = 0; i < n; i++) {
    int mini = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[mini]) {
        mini = j;
      }
    }

    if (mini != i) {
      int temp = a[i];
      a[i] = a[mini];
      a[mini] = temp;
      swap++;
    }
  }

  for (int l = 0; l < n-1; l++) {
    printf("%d ", a[l]);
  }
  printf("%d\n", a[n-1]);
  printf("%d\n", swap);

  return 0;
}
