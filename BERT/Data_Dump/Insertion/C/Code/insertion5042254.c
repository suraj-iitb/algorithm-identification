#include <stdio.h>

int main(){
  int i, j, n, v;
  int c;
  int a[1000];

  scanf("%d", &n);

  if(n < 1 || n > 100) return 0;

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(c = 0; c < n-1; c++){
      printf("%d ", a[c]);
  }

  printf("%d\n", a[n-1]);

  for(i = 1; i < n; i++){
    v = a[i];
    j = i - 1;

    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }

    a[j+1] = v;

    for(c = 0; c < n-1; c++){
      printf("%d ", a[c]);
    }

    printf("%d\n", a[n-1]);
  }

  return 0;
}

