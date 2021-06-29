#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i = 0;
  int k = 0;
  int j = 0;
  int n;
  int input;
  int *num;
  int temp;

  scanf("%d", &n);
  num = (int *)malloc(n * sizeof(int));

  for(i = 0; i < n; i++){
    scanf("%d", &input);
    num[i] = input;
  }

  for(i = 0; i < n; i++){
    printf("%d", num[i]);
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n");

  for(i = 1; i < n; i++){
    for(k = i; k > 0; k--){
      if(num[k] < num[k-1]){
        temp = num[k-1];
        num[k-1] = num[k];
        num[k] = temp;
      }else {
        break;
      }
    }
    for(j = 0; j < n-1; j++){
      printf("%d ", num[j]);
    }
    printf("%d", num[n-1]);
    printf("\n");
  }
}
