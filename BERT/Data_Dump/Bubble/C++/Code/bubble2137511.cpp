#include <stdio.h>

#define MAX_N 100

int bubble_sort(int* as, int n) {
  int flag = 1;
  int tmp = 0;
  int swapped_num = 0;
  while(flag) {
    flag = 0;
    for(int j=n-1; j>0; j--) {
      if (as[j] < as[j-1]) {
        tmp = as[j];
        as[j] = as[j-1];
        as[j-1] = tmp;
        swapped_num++;
        flag = 1;
      }
    }
  }
  return swapped_num;
}

int main() {
  int n;
  int a[MAX_N];
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  int swapped_num = bubble_sort(a, n);

  for(int i=0; i<n; i++) {
    printf("%d", a[i]);
    if(i != n-1) {
      printf(" ");
    }
  }

  printf("\n%d\n", swapped_num);
}
