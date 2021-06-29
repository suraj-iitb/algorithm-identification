#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
  int n, q;

  
  scanf("%d", &n);
  int arr_s[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr_s[i]);
  }

  scanf("%d", &q);
  int arr_t[q];
  for (int i = 0; i < q; i++) {
    scanf("%d", &arr_t[i]);
  }

  int count = 0;

  for (int i = 0; i < q; i++) {
    for (int j = 0; j < n; j++) {
      if (arr_t[i] == arr_s[j]) {
        count++;
        break;
      }
    }
  }

  printf("%d\n", count);

}

