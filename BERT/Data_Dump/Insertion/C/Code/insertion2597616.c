#include <stdio.h>

int main(void)
{
  int a[1000];
  int i, v, j, k, N;

  scanf("%d", &N);
 
  for(i = 0; i < N; i++)
    scanf("%d", &a[i]);
  
  for(k = 0; k < N; k++) {
      if(k > 0)
        printf(" ");
      printf("%d", a[k]);
  }
  printf("\n");

  for(i = 1; i < N; i++) {
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    for(k = 0; k < N; k++) {
      if(k > 0)
        printf(" ");
      printf("%d", a[k]);
    }
    printf("\n");
  }

  return 0;
}
