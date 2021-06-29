#include <stdio.h>

#define N 100


int main() {
  int n, i, j, l, key, data[N];

  scanf("%d", &n);
  
  for (i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  for (i = 1; i < n; i++) {
    for (l = 0; l < n; l++) {
      printf("%d", data[l]);
      if (l != n-1) printf(" ");
    }
    printf("\n");
    key = data[i];
    j = i-1;
    while(j >= 0 && data[j] > key) {
      data[j+1] = data[j]; 
      j--;
    }
    data[j+1] = key;
    
  }

  for (l = 0; l < n; l++) {
      printf("%d", data[l]);
      if (l != n-1) printf(" ");
    }
  printf("\n");

  return 0;
}

