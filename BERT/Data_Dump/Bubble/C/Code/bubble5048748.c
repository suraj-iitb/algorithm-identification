#include <stdio.h>

int main(){
  int data[100];
  int count = 0, n, i, j, flag = 1, buffer;
  
  scanf("%d", &n); /* 配列の要素数 */
  for(i = 0; i < n; i++){
    scanf("%d", &data[i]); /* 要素の格納 */
  }
  
  while(flag != 0){
    flag = 0;
    for(j = n-1; j > 0; j--){
      if(data[j] < data[j-1]){
        buffer = data[j-1];
        data[j-1] = data[j];
        data[j] = buffer;
        flag = 1;
        count++;
      }
    }
  }
  for(i = 0; i < n; i++){
    printf("%d", data[i]);
    if(i == n-1){printf("\n");}
    else{printf(" ");}
  }
  printf("%d\n", count);
  return 0;
}

