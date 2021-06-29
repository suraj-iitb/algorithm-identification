#include <stdio.h>
#define N 101

int main() {
  int i, j, n, a[N], v;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(i = 1; i < n; i++){
    for(j = 0; j < n; j++) {
      printf("%d", a[j]);
      if(j < n-1){
        printf(" ");
      }
    }
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    printf("\n");
  }
  for(j = 0; j < n; j++){
    printf("%d", a[j]);
    if(j < n-1){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}
