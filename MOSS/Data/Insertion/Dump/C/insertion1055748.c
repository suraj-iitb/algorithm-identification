#include <stdio.h>
#define MAX 100
int main(void){
  int i, j, k, n, temp, d[MAX];
  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &d[i]);
  }

  for(i = 0; i < n; i++){
    if(i > 0){
      printf(" ");
    }
    printf("%d", d[i]);
  }
  printf("\n");

  for(i = 1; i <= n - 1; i++){
    temp = d[i];
    j = i - 1;
    while(j >= 0 && d[j] > temp){
      d[j + 1] = d[j];
      j--;
    }
    d[j + 1] = temp;

    for(k = 0; k < n; k++){
      if(k > 0){
        printf(" ");
      }
      printf("%d", d[k]);
    }
    printf("\n");
  }


  return 0;
}
