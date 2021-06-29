#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i = 0;
  int k = 0;
  int j = 0;
  int n;
  int input;
  int *num;
  int swapNum = 0;
  int temp;
  int flag = 1;

  scanf("%d", &n);
  num = (int *)malloc(n * sizeof(int));

  for(i = 0; i < n; i++){
    scanf("%d", &input);
    num[i] = input;
  }

  if(n > 1)
  while(flag){
    flag = 0;
    for(i = n-1; i > 0; i--){
      if(num[i] < num[i-1]){
        temp = num[i-1];
        num[i-1] = num[i];
        num[i] = temp;
        swapNum++;
        flag = 1;
      }
    }
  }
  for(i = 0; i < n; i++){
    printf("%d", num[i]);
    if(i < n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n", swapNum);

  return 0;
}
