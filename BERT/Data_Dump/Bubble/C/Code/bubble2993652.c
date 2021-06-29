#include <stdio.h>
int main(void){
  int i, j, cnt = 0, flag, k;
  int numbers[100];
 
  scanf("%d", &k);
   
  for(i = 0;i < k;i++){
    scanf("%d", &numbers[i]);
  }
 
  flag = 1;
  while(flag){
    flag = 0;
      for(j=k-1;j>=1;j--){
        if(numbers[j] < numbers[j-1]){
          i = numbers[j-1];
          numbers[j-1] = numbers[j];
          numbers[j] = i;
          flag = 1;
          cnt++;
        }
      }
 
  }
  for(i = 0;i < k-1;i++){
    printf("%d ", numbers[i]);
  }
  printf("%d\n", numbers[i]);
  printf("%d\n", cnt);
  return 0;
}
